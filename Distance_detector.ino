void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(13,LOW);
  delayMicroseconds(2);
  digitalWrite(13,HIGH);
  delayMicroseconds(10);
  digitalWrite(13,LOW);
  int time = pulseIn(12,HIGH);
  int dist = time*0.034/2;
  Serial.println(dist);
  
  if(dist>3 && dist<10){
    digitalWrite(7,HIGH);
    delay(2000);
    digitalWrite(7,LOW);
  }
  else if(dist>11 && dist<15){
    digitalWrite(5,HIGH);
    delay(2000);
    digitalWrite(5,LOW);
  }
  else{
    digitalWrite(2,HIGH);
    delay(2000);
    digitalWrite(2,LOW);
  }
}
