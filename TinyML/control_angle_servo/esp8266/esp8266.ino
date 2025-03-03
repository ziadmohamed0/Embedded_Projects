/**
 * @file esp8266.ino
 * @author Ziad Mohammed Fathy
 * @brief ESP8266-based MQTT-controlled servo motor system.
 * @version 0.1
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
#define SERVO_CHANNEL 0
#define SERVO_MIN 150
#define SERVO_MAX 600

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
 * @param angle The target angle for the servo motor.
 */
void moveServo(int angle) {
    int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
    pwm.setPWM(SERVO_CHANNEL, 0, pulse);
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
    
    float distance = message.toFloat();
    int angle = mapDistanceToAngle(distance);
    
    moveServo(angle);
    Serial.print("Received Distance: ");
    Serial.print(distance);
    Serial.print(" -> Servo Angle: ");
    Serial.println(angle);
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
}

/**
 * @brief Handles MQTT communication in the main loop.
 */
void loop() {
    client.loop();
}
