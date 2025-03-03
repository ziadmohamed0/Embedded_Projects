#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP8266WiFi.h>

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver();

#define WIFI_SSID "" 
#define WIFI_PASSWORD ""
#define SERVER_PORT 5000 

WiFiServer server(SERVER_PORT);

#define SERVO_MIN 150 
#define SERVO_MAX 600 


int servoChannels[] = {0, 1, 2, 3, 4, 5};

void setup() {
  Serial.begin(115200);

  pca9685.begin();
  pca9685.setPWMFreq(50);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  server.begin();
}

void setServoAngle(uint8_t channel, int angle) {
  int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pca9685.setPWM(channel, 0, pulse);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String data = client.readStringUntil('\n');
    Serial.println("Received Data: " + data);

    float accelX, accelY, accelZ, gyroX, gyroY, gyroZ;
    int irValue;
    sscanf(data.c_str(), "%f,%f,%f,%f,%f,%f,%d", &accelX, &accelY, &accelZ, &gyroX, &gyroY, &gyroZ, &irValue);

    int baseAngle = map(accelX, -10, 10, 0, 180);
    int armAngle = map(accelY, -10, 10, 0, 180);

    setServoAngle(servoChannels[0], baseAngle); 
    setServoAngle(servoChannels[1], armAngle); 

    if (irValue == HIGH) {
      setServoAngle(servoChannels[5], 90);
    } else {
      setServoAngle(servoChannels[5], 0); 
    }
  }
}
