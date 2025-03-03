/**
 * @file esp8266_multi_servo.ino
 * @author Ziad Mohamed Fathy
 * @brief ESP8266-based MQTT-controlled multi-servo motor system.
 * @version 0.3
 * @date 2025-03-03
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/* MQTT Configurations */
const char* ssid = "Mohamed Fathy";
const char* password = "341978341978";
const char* mqtt_server = "192.168.100.25";
const char* mqtt_topic = "hand_gesture/distance";

/* PCA9685 Driver Configurations */
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
#define NUM_SERVOS 5
#define SERVO_MIN 150
#define SERVO_MAX 600

const int servoChannels[NUM_SERVOS] = {0, 1, 2, 3, 4};

WiFiClient espClient;
PubSubClient client(espClient);

/**
 * @brief Maps a distance value to a servo angle.
 * 
 * @param distance The measured distance.
 * @return int The corresponding servo angle.
 */
int mapDistanceToAngle(float distance) {
    int angle = map(distance, 10, 150, 0, 180);
    return constrain(angle, 0, 180);
}

/**
 * @brief Moves the servo motor to a specified angle.
 * 
 * @param servoIndex The servo index (0 to 4).
 * @param angle The target angle for the servo motor.
 */
void moveServo(int servoIndex, int angle) {
    int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
    pwm.setPWM(servoChannels[servoIndex], 0, pulse);
    Serial.print("Moving Servo ");
    Serial.print(servoIndex);
    Serial.print(" to Angle: ");
    Serial.println(angle);
}

/**
 * @brief Callback function for handling received MQTT messages.
 * 
 * @param topic The topic of the received MQTT message.
 * @param payload The message payload.
 * @param length The length of the payload.
 */
void callback(char* topic, byte* payload, unsigned int length) {
    String message = "";
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }

    Serial.print("Received Data: ");
    Serial.println(message);

    float distances[NUM_SERVOS] = {90, 90, 90, 90, 90};
    int index = 0;
    char* token = strtok((char*)message.c_str(), ",");
    
    while (token != NULL && index < NUM_SERVOS) {
        distances[index] = atof(token);
        Serial.print("Distance ");
        Serial.print(index);
        Serial.print(": ");
        Serial.println(distances[index]);
        token = strtok(NULL, ",");
        index++;
    }

    for (int i = 0; i < NUM_SERVOS; i++) {
        int angle = mapDistanceToAngle(distances[i]);
        moveServo(i, angle);
    }
}


/**
 * @brief Initializes WiFi, MQTT, and PCA9685 servo driver.
 */
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected");

    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    
    while (!client.connected()) {
        Serial.print("Connecting to MQTT...");
        if (client.connect("ESP8266Client")) {
            Serial.println("Connected!");
            client.subscribe(mqtt_topic);
        } else {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" trying again...");
            delay(2000);
        }
    }

    pwm.begin();
    pwm.setPWMFreq(50);

    // Initialize all servos to 90 degrees
    for (int i = 0; i < NUM_SERVOS; i++) {
        moveServo(i, 90);
        delay(200);
    }
}

/**
 * @brief Handles MQTT communication in the main loop.
 */
void loop() {
    client.loop();
}
