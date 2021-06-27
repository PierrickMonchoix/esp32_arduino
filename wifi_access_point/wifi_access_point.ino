#include <WiFi.h>

const char* ssid = "esp_acces_point";
const char* password = "azertyuiop";

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");
  
  Serial.println("Creation du point d'acces...");
  WiFi.softAP(ssid, password);
  
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop()
{
  
}
