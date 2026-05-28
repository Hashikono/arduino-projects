#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

int m = 0;

void setup()
{
  lcd_1.begin(16,2);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, INPUT);
  lcd_1.print("Motor Status");
}

void loop()
{
  m = digitalRead(7);
  lcd_1.setCursor(13, 0);
  if (m == HIGH) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    Serial.println("Motor ON");
    lcd_1.print("ON ");
  }
  else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    Serial.println("Motor OFF");
    lcd_1.print("OFF");
  }
}