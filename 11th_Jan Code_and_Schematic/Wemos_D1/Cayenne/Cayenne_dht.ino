


#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space


#include "ESP8266WiFi.h"
#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"
#include <DHT.h>    //라이브러리 불러옴

#define DHTPIN  13
#define DHTTYPE DHT11

#define VIRTUAL_PIN V4

           //Signal 이 연결된 아두이노의 핀번호 

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = “yours”;
// Your network name and password.
char ssid[] = “KT_203”;
char password[] = “1234567!kt”;

float h;
float t;
bool Humi = false;
bool Temp = false;

DHT dht(DHTPIN, DHTTYPE);
//int sensor_pin=14;
void setup()
{

  Serial.begin(9600);
  Cayenne.begin(token, ssid, password);
  

}

void loop()
{
  Cayenne.run();
}



CAYENNE_OUT(V0){
  //Serial.println("Umidade");

  //Check if read failed and try until success
  do {
    //Read humidity (percent)
    h = dht.readHumidity();

    delay(1000);
  } while  (isnan(h));

  Serial.print("Humi: ");
  Serial.println(h);

  //Write to Cayenne Dashboard
  Cayenne.virtualWrite(V0, h);
}

CAYENNE_OUT(V1){
  //Serial.println("Temperatura");
  
  //Check if read failed and try until success
  do {
    //Read temperature as Celsius
   
    t = dht.readTemperature();
    
    delay(1000);
  } while  (isnan(t));

  Serial.print("Temp: ");
  Serial.println(t);

  //Write to Cayenne Dashboard
  Cayenne.virtualWrite(V1, t);
}



