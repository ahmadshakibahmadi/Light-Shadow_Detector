#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to 0x3F if your LCD uses that

int sensorPin = A0;  
int sensorValue = 0;
int buzzerPin = 8;  
int threshold = 300; // Adjust this value for your light level

void setup() {
  lcd.init();      
  lcd.backlight(); 
  pinMode(buzzerPin, OUTPUT);
  
  lcd.setCursor(0,0);
  lcd.print("Light Sensor");
  delay(1000);
}

void loop() {
  sensorValue = analogRead(sensorPin); 

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Light Level:");
  lcd.setCursor(0,1);
  lcd.print(sensorValue);

  // DARK = low value → buzzer ON
  if(sensorValue < threshold) {
    digitalWrite(buzzerPin, HIGH);  // Buzzer ON
    lcd.setCursor(10,0);
    lcd.print("Dark");
  } 
  else {
    digitalWrite(buzzerPin, LOW);   // Buzzer OFF
    lcd.setCursor(10,0);
    lcd.print("Bright");
  }

  delay(500);
}


