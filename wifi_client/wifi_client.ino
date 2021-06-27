#include <WiFi.h>
#include <ESP32Ping.h>

const char* ssid = "Gryfondor";
const char* password = "azertyuiop";

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n");

  WiFi.persistent(false);
  WiFi.begin(ssid, password);
  Serial.print("Tentative de connexion...");
  
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  
  Serial.println("\n");
  Serial.println("Connexion etablie!");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());

  IPAddress raspi (192, 168, 43, 29);

  bool success;
  while(true){
    delay(1000);
    success = Ping.ping(raspi, 3);
    if(success){
      Serial.println("Ping   OK");
      Serial.print("Time:   ");
      Serial.println(Ping.averageTime());
    }
    else{
      Serial.println("Ping   NOK");
    }
  }

  
}

void loop()
{
  
}
