#include <DHT11.h>    //라이브러리 불러옴
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int pin=13;            //Signal 이 연결된 아두이노의 핀번호
DHT11 dht11(pin);      
LiquidCrystal_I2C lcd(0x27, 16, 2);
  
void setup()
{
   Serial.begin(9600); //통신속도 설정
   lcd.begin();

  // Turn on the blacklight and print a message.
   lcd.backlight();
}
 
void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0) //온도, 습도 읽어와서 표시
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
     
    lcd.setCursor(0,0);
    lcd.print("T:");
    lcd.print(temp);
  }
  else                                //에러일 경우 처리
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(1000);                        //1초마다 측정
}
 
