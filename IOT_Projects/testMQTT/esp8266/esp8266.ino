#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Mohamed Fathy";
const char* password = "341978341978";
const char* mqtt_server = "192.168.100.90";  

WiFiClient espClient;
PubSubClient client(espClient);

#define sensorPin D2

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int sensorValue = digitalRead(sensorPin); 
  char msg[50];
  sprintf(msg, "ESP8266 Sensor Value: %d", sensorValue);  
  client.publish("esp8266/sensor", msg);  

  delay(1000); 
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP8266Client")) {
      client.subscribe("esp8266/sensor");
    } else {
      delay(5000);
    }
  }
}
