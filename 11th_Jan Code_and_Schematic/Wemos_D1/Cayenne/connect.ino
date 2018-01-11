

#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space


#include "ESP8266WiFi.h"
#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = “your”;
// Your network name and password.
char ssid[] = “KT_203”;
char password[] = “1234567!kt”;



void setup()
{

  Serial.begin(9600);
  Serial.println("Connetion test!");
  Cayenne.begin(token, ssid, password);
  
 // Humi = false;
 // Temp = false;

}

void loop()
{
  Cayenne.run();
}
