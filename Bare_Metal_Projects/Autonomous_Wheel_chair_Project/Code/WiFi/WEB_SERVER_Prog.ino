#include "WEB_SERVER_Init.h"

/****** HTML WEB SERVER CODE ******/
void handleRoot()
{
  String html = "<!DOCTYPE html><html><head>";
  html += "<title>Zzrad</title><style>.button-container { display: flex; justify-content: center; align-items: center; height: 100vh; }";
  html += ".button1 { background-color: #202467; color: #ffffff; font-size: xx-large; }";
  html += ".button2 { background-color: #202467; color: #ffffff; font-size: xx-large; }";
  html += ".button3 { background-color: #202467; color: #ffffff; font-size: xx-large; }";
  html += ".button4 { background-color: #202467; color: #ffffff; font-size: xx-large; }";
  html += "</style></head><body>";
  html += "<div class=\"button-container\"><div><h1>Autonomous Chair system</h1>";
  html += "<button class=\"button1\" onclick=\"sendNumber(1)\">Pharmacy</button><br>";
  html += "<button class=\"button2\" onclick=\"sendNumber(2)\">X-ray lab</button><br>";
  html += "<button class=\"button3\" onclick=\"sendNumber(3)\">Laboratory</button><br>";
  html += "<button class=\"button4\" onclick=\"sendNumber(0)\">Return Home</button><br>";
  html += "</div></div>";
  html += "<script>function sendNumber(num) { var xhr = new XMLHttpRequest(); xhr.open('GET', '/send?number=' + num, true); xhr.send(); }";
  html += "</script></body></html>";
  server.send(200, "text/html", html);
}