#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Mohamed Fathy";
const char* password = "341978341978";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
char msg[50];
int value = 0;

void callback(char* topic, byte* payload, unsigned int length);
void setup_wifi(void);
void reconnect(void);

void setup(void) {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi(void) {
  delay(10);
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String string;
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    string += ((char)payload[i]);
  }
  Serial.println(string);

  if (strcmp(topic, "/FOTA/test") == 0) {
    Serial.print("Received: ");
    Serial.println(string);
  }
}

void reconnect(void) {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESPClient")) {
      Serial.println("connected");
      client.subscribe("/FOTA/test");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop(void) {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  delay(100);
}
