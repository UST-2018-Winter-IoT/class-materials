int soundSensor = 16;
int LED =5;
void setup()
{
  pinMode (soundSensor, INPUT);
  pinMode (LED, OUTPUT);
}

void loop()
{
  int statusSensor = digitalRead(soundSensor); // read input value

  if(statusSensor == 1)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}
