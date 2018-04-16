#include "ESP8266WiFi.h"

const int LedPin = 2;

void setup() {
  pinMode(LedPin, OUTPUT);
  
  Serial.begin(9600);  
    
  WiFi.mode(WIFI_STA);
  WiFi.persistent(false);
  WiFi.disconnect();
  delay(100);
}

void loop() {  
  Serial.print("Scan start ... ");
  digitalWrite(LedPin, LOW);
  int n = WiFi.scanNetworks(false, true);  
  Serial.printf("%d network(s) found\n", n);
  for (int i = 0; i < n; i++)
  {     
    String ssid = WiFi.SSID(i);
    uint8_t encryption = WiFi.encryptionType(i);
    int32_t rssi = WiFi.RSSI(i);
    
    uint8_t* bssid = WiFi.BSSID(i);    
    String bssidStr = WiFi.BSSIDstr(i);
    
    int32_t channel = WiFi.channel(i);
    bool isHidden = WiFi.isHidden(i);

    String isOpen = encryption == ENC_TYPE_NONE ? "Open" : "Encrypted";
    String isHiddenStr = isHidden ? "[Hidden]" : "Visible";

    String encryptionType;
    
    switch(encryption)
    {
      case ENC_TYPE_WEP:
        encryptionType = "WEP";
        break;
      case ENC_TYPE_TKIP:
        encryptionType = "WPA/PSK";
        break;              
      case ENC_TYPE_CCMP:
        encryptionType = "WPA2/PSK";
        break;              
      case ENC_TYPE_AUTO:
        encryptionType = "WPA/WPA 2/PSK";
        break;          
      default:
        encryptionType = " - ";
        break;                 
    }

    //WiFi.getNetworkInfo(i, ssid, encryption, rssi, bssid, channel, isHidden);
    Serial.printf("%d. %s, Ch:%d (%ddBm) %s (%s) %s\n", i + 1, ssid.c_str(), channel, rssi,  isOpen.c_str(), encryptionType.c_str(), isHiddenStr.c_str());    
  }
  
  digitalWrite(LedPin, HIGH);
  Serial.println();

  delay(5000);
}
