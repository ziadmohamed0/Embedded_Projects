#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>

Adafruit_MPU6050 mpu;

#define IR_SENSOR_PIN 15
#define WIFI_SSID "" 
#define WIFI_PASSWORD "" 
#define SERVER_IP ""
#define SERVER_PORT 5000 

WiFiClient client;

void setup() {
  Serial.begin(115200);

  if (!mpu.begin()) {
    Serial.println("MPU6050 initialization failed!");
    while (1);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

  pinMode(IR_SENSOR_PIN, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  int irValue = digitalRead(IR_SENSOR_PIN);

  Serial.println("MPU6050 Data:");
  Serial.print("Accel X: "); Serial.println(a.acceleration.x);
  Serial.print("Accel Y: "); Serial.println(a.acceleration.y);
  Serial.print("Accel Z: "); Serial.println(a.acceleration.z);
  Serial.print("Gyro X: "); Serial.println(g.gyro.x);
  Serial.print("Gyro Y: "); Serial.println(g.gyro.y);
  Serial.print("Gyro Z: "); Serial.println(g.gyro.z);
  Serial.print("IR Value: "); Serial.println(irValue);

  String data = String(a.acceleration.x) + "," + String(a.acceleration.y) + "," +
                String(a.acceleration.z) + "," + String(g.gyro.x) + "," +
                String(g.gyro.y) + "," + String(g.gyro.z) + "," + String(irValue);

  if (client.connect(SERVER_IP, SERVER_PORT)) {
    client.println(data);
    client.stop();
  }

  delay(1000);
}
