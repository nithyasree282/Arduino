void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(5000);
  digitalWrite(2, LOW);
  
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  
  digitalWrite(7,HIGH);
  delay(5000);
  digitalWrite(7,LOW);
}
