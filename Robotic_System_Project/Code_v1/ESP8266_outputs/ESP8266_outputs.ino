#include <ESP8266WiFi.h>
#include <Servo.h>

const char* ssid = "";
const char* password = "";
WiFiServer server(8080);

Servo servo1, servo2, servo3, servo4, servo5, servoEndEffector;

#define IR_PIN D2

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  servo1.attach(D1);
  servo2.attach(D2);
  servo3.attach(D3);
  servo4.attach(D4);
  servo5.attach(D5);
  servoEndEffector.attach(D6);

  pinMode(IR_PIN, INPUT);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi.");

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected() && client.available()) {
      String data = client.readStringUntil('\n');
      Serial.println("Received Data: " + data);

      float accelX = data.substring(0, data.indexOf(',')).toFloat();
      data = data.substring(data.indexOf(',') + 1);
      float accelY = data.substring(0, data.indexOf(',')).toFloat();
      float accelZ = data.substring(data.indexOf(',') + 1).toFloat();

      int angle1 = map(accelX, -10, 10, 0, 180);
      int angle2 = map(accelY, -10, 10, 0, 180);
      int angle3 = map(accelZ, -10, 10, 0, 180);

      servo1.write(angle1);
      servo2.write(angle2);
      servo3.write(angle3);
    }
    client.stop();
  }

  if (digitalRead(IR_PIN) == LOW) { 
    servoEndEffector.write(0); 
  } else {
    servoEndEffector.write(90); 
  }

  delay(100);
}
