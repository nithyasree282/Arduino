#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LDR_PIN = A0;
const int DARK_THRESHOLD = 190;
const int MEDIUM_THRESHOLD = 290;

void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LDR Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);
  String lightLevel = categorizeLight(sensorValue);

  Serial.print("Light Level: ");
  Serial.println(lightLevel);
  Serial.print("LDR Value: ");
  Serial.println(sensorValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print(lightLevel);

  lcd.setCursor(0, 1);
  lcd.print("LDR Val: ");
  lcd.print(sensorValue);

  delay(3000);
}

String categorizeLight(int value) {
  if (value < DARK_THRESHOLD) return "DARK";
  else if (value < MEDIUM_THRESHOLD) return "MEDIUM";
  else return "BRIGHT";
}
