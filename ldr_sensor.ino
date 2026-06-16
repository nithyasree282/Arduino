const int LDR_PIN = A0;
const int DARK_THRESHOLD = 190;
const int MEDIUM_THRESHOLD = 290; 
const int red = 2;
const int yellow = 3;
const int green = 4; 

void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);
  
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

  String lightLevel = categorizeLight(sensorValue);  
  Serial.print("Light Level: ");
  Serial.println(lightLevel);
  Serial.print("LDR Value: ");
  Serial.println(sensorValue);

  if (sensorValue < DARK_THRESHOLD) {
    digitalWrite(red, HIGH);
  } 
  else if (sensorValue < MEDIUM_THRESHOLD) {
    digitalWrite(yellow, HIGH);
  } 
  else {
    digitalWrite(green, HIGH);
  }
  
  delay(3000);
}

String categorizeLight(int value) {
  if (value < DARK_THRESHOLD) {
    return "DARK";
  } 
  else if (value < MEDIUM_THRESHOLD) {
    return "MEDIUM";
  } 
  else {
    return "BRIGHT";
  }
}
