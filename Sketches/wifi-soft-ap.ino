#include "ESP8266WiFi.h"

const int LedPin = 2;

void setup() {
  pinMode(LedPin, OUTPUT);
  
  Serial.begin(9600);  
  
  digitalWrite(LedPin, LOW);
  
  Serial.print("Setting soft-AP ...");
  
  WiFi.persistent(false);
  boolean result = WiFi.softAP("ESPsoftAP_01", "pass1234");

  //Serial.setDebugOutput(true);
  
  digitalWrite(LedPin, HIGH);  
  
  if (result == true)
  {
    Serial.println("Ready");
  }
  else
  {
    Serial.println("Failed!");
  }
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  //WiFi.printDiag(Serial);
  delay(5000);

}
