/* includes */
#include <WiFi.h>
#include <PubSubClient.h>

/* wifi & mqtt variables */
const char* ssid = "Mohamed Fathy";
const char* pass = "341978341978";
const char* mqtt_server = "192.168.100.25";
const char* mqtt_topic_ultrasonic = "sensor/ultrasonic";
const int   mqtt_port = 1883;

/* pins numbers */
#define trigPin   16
#define echoPin   17
#define buzzerPin 5

/* clients variable */
WiFiClient espClient;
PubSubClient client(espClient);

/* Functions Prototypes */
void setup_wifi();
unsigned int readDistance(void);
void sendDistance(unsigned int distance);
void buzzBuzzer(unsigned int distance);
void reconnect(void);
void callback(char* topic, byte* payload, unsigned int length);

/* Set Up Function */
void setup(void) {
  Serial.begin(115200);                       // serial intialization
  setup_wifi();                               // initialization wifi
  client.setServer(mqtt_server, mqtt_port);   // initialization mqtt server
  client.setCallback(callback);               // initialization call back function

  /* initialization Pins Direction */
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

/* Program Function */
void loop(void) {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned int distance = readDistance();
  sendDistance(distance);
  buzzBuzzer(distance);

  delay(1000);
}

/**
  * @brief function connect esp32 to local wifi if not conected the programe not exit from while loop.
  */
void setup_wifi(void) {
  delay(10);
  WiFi.begin(ssid, pass);
  if(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi is connected");
}

/**
  * @brief function read distance from ultrasonic and return distance in int value.
  */
unsigned int readDistance(void){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  unsigned int duration = pulseIn(echoPin, HIGH);
  unsigned int distance = (duration / 2) / 29.1;
  return distance;
}

/**
  * @brief function send distance payload to mqtt broker.
  */
void sendDistance(unsigned int distance) {
  char dis[4];
  itoa(distance, dis, 10);
  client.publish(mqtt_topic_ultrasonic, dis);
}

/**
  * @brief function check if distance < 10 cm then buzzer sound on else buzzer sound off.
  */
void buzzBuzzer(unsigned int distance) {
  if (distance < 5) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}

/**
  * @brief function call back publish payload to broker.
  */
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  static unsigned int distance = 0;
  if (String(topic) == mqtt_topic_ultrasonic) {
    distance = message.toInt();
  }
}

/**
  * @brief function reconnect to mqtt broker.
  */
void reconnect(void) {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe(mqtt_topic_ultrasonic);
    } else {
      delay(5000);
    }
  }
}