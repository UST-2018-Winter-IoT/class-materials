
void setup()
{
pinMode(16, OUTPUT); // pin 2 to 5 is set as output 
pinMode(5, OUTPUT); 
pinMode(4, OUTPUT);
pinMode(14, OUTPUT);
}
 
 void loop()
{
digitalWrite(16, HIGH);//LED 1 is ON
delay(500); // wait half a second
digitalWrite(16, LOW); // Turn LED 1 off
digitalWrite(5, HIGH); // and repeat for LED 2 to 5
delay(500);
digitalWrite(5, LOW);
digitalWrite(4, HIGH);
delay(500);
digitalWrite(4, LOW);
digitalWrite(14, HIGH);
delay(500);
digitalWrite(14, LOW);
}
 
