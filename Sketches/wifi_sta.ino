#include "ESP8266WiFi.h"

const int LedPin = 2;

void setup() {
  pinMode(LedPin, OUTPUT);
  
  Serial.begin(9600);  

  digitalWrite(LedPin, LOW);
  
  WiFi.persistent(false);
  WiFi.begin("ssid", "password");

  Serial.setDebugOutput(true);
  
  Serial.printf("Connecting");  
  
  while(WiFi.status() != WL_CONNECTED){
    digitalWrite(LedPin, HIGH);
    delay(500);
    digitalWrite(LedPin, LOW);
    Serial.print(".");
  }

  digitalWrite(LedPin, HIGH);
  Serial.println();

  String ipAddress = WiFi.localIP().toString();
  Serial.printf("Connected, IP address: %s\n", ipAddress.c_str());
  
  WiFi.printDiag(Serial);  
}

void loop() {
  
}
