#include <DHT11.h>    //라이브러리 불러옴
#include "TM1637.h"

int pin=16;            //Signal 이 연결된 아두이노의 핀번호
DHT11 dht11(pin);      
#define CLK 5//Pins for TM1637       
#define DIO 4

TM1637 tm1637(CLK,DIO);
  
void setup()
{
   Serial.begin(9600); //통신속도 설정
   tm1637.init();
   tm1637.set(BRIGHT_TYPICAL); 
}
 
void loop()
{
  int err;
  float temp, humi;
  int temp_i;
  if((err=dht11.read(humi, temp))==0) //온도, 습도 읽어와서 표시
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
    
    temp_i = (int)temp;

    int digitoneT = temp_i / 10;
    int digittwoT = temp_i % 10;

    tm1637.display(1,digitoneT); 
    tm1637.display(2,digittwoT);
    tm1637.display(3,12);  // put a C at the end
    
    delay (3000);
    
  }
  else                                //에러일 경우 처리
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }                      //1초마다 측정
}
 
