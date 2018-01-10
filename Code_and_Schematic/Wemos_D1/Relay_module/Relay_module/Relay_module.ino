const int BUTTON1 = 5;
const int ledPin =  16; 

int buttonState = 0;
int flag=0;

void setup()
{
  Serial.begin(9600);

  pinMode(ledPin,OUTPUT);
  pinMode(BUTTON1,INPUT);
}

void loop()
{
  Serial.println( );
  if(digitalRead(BUTTON1) == HIGH)
  { 
    Serial.println("Button1 1");
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("Button1 0");
  } 
  delay(200);
}
