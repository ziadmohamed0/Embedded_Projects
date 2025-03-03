#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <ESP8266WiFi.h>

Adafruit_MPU6050 mpu;

const char* ssid = "";
const char* password = "";
const char* host = ""; 
const uint16_t port = 8080;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Wire.begin();
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1) { delay(10); }
  }

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi.");
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  String data = String(a.acceleration.x) + "," +
                String(a.acceleration.y) + "," +
                String(a.acceleration.z);

  WiFiClient client;
  if (client.connect(host, port)) {
    client.println(data);
    client.stop();
  }

  delay(100); 
}
