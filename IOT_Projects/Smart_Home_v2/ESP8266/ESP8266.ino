#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const char* ssid = "Mohamed Fathy";
const char* password = "341978341978";

const char* mqtt_server = "192.168.100.25";
const int mqtt_port = 1883;
const char* ir_topic = "ir/sensors";
const char* password_topic = "password/topic";

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVO_MIN 150
#define SERVO_MID 375
#define SERVO_MAX 600

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
    String message = "";
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }

    if (String(topic) == ir_topic) {
        message.replace("[", "");
        message.replace("]", "");
        message.replace(" ", "");

        int sensor1 = message.substring(0, 1).toInt();
        int sensor2 = message.substring(2, 3).toInt();
        int sensor3 = message.substring(4, 5).toInt();

        control_servo(1, sensor1);
        control_servo(2, sensor2);
        control_servo(3, sensor3);
    }

    if (String(topic) == password_topic) {
        if (message == "123456") {
            pwm.setPWM(0, 0, SERVO_MID);
            Serial.println("Password correct! Servo moved to 90 degrees.");

            delay(5000);
            pwm.setPWM(0, 0, SERVO_MIN);
            Serial.println("Servo returned to 0 degrees.");
        } else {
            Serial.println("Incorrect password. No action taken.");
        }
    }
}

void control_servo(int servo_num, int sensor_value) {
    if (sensor_value == 1) {
        pwm.setPWM(servo_num, 0, SERVO_MIN);
    } else {
        pwm.setPWM(servo_num, 0, SERVO_MID);
    }
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP8266Client")) {
            Serial.println("connected");
            client.subscribe(ir_topic);
            client.subscribe(password_topic);
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);

    pwm.begin();
    pwm.setPWMFreq(50);
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
}