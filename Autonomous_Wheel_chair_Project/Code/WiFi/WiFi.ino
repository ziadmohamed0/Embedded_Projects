#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "INIT_Init.h"
/****** Wi-Fi credentials ******/
const char* ssid = "realme C67";
const char* password = "123456789";

/****** Rooms Flag ******/
unsigned int Flage_Rooms = 0;

// Initialize the web server on port 80
ESP8266WebServer server(80);

/****** Initialization Program ******/
void handleSend()
{
  // Get the "number" parameter from the URL query string
  String number = server.arg("number");

  // Print the number to the serial monitor.
  Serial.print("Received number: ");
  Serial.println(number);
  int Distance = 0;
  int Duration = 0;

  digitalWrite(TRIG, LOW);
  delay(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  Duration = pulseIn(ECHO, HIGH);

  Distance = Duration / 57.14;
  // Respond to the client
  server.send(200, "text/plain", "Number received");
  int num = number.toInt();

  if (Distance < 10) 
  {
    digitalWrite(BUZZ, HIGH);
    delay(2000);
    digitalWrite(BUZZ, LOW);
    Motor_Stop();
    delay(25);
  } 
  else 
  {
    digitalWrite(BUZZ, LOW);
    if (num == 0)
    {
      Home();
      server.send(200, "text/plain", "ENTERED Home");
      Serial.println("ENTERED Home");
      Serial.println(Distance);
      delay(500);
    }

    if (num == 1)
    {
      pharmacy();
      server.send(200, "text/plain", "ENTERED ROOM 1");
      Serial.println("ENTERED pharmacy");
      Serial.println(Distance);
      delay(500);
    }
    if (num == 2) 
    {
      // Tgo to second room
      X_ray();
      server.send(200, "text/plain", "ENTERRD ROOM 2");
      Serial.println("ENTERED X-Ray Lab");
    }
    if (num == 3) 
    {
      // Tgo to second room
      laboratory();
      server.send(200, "text/plain", "ENTERRD ROOM 3");
      Serial.println("ENTERED laboratory");
    }
  }
}

void setup() 
{
  // Start the serial monitor
  Serial.begin(115200);

  // Connect to the Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println("IP address: " + WiFi.localIP().toString());

  // Set up the handlers for the web server
  server.on("/", handleRoot);
  server.on("/send", handleSend);

  // Start the web server
  server.begin();
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(BUZZ, OUTPUT);
}

void loop() 
{
  // Handle incoming client requests
  int Distance = 0;
  int Duration = 0;

  digitalWrite(TRIG, LOW);
  delay(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  Duration = pulseIn(ECHO, HIGH);

  Distance = Duration / 57.14;

  server.handleClient();
  Serial.println(Distance);
  delay(500);
}


