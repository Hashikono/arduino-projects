#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//regular stuff
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    
    while (millis() < 1000) {
        sensorValue = analogRead(A0);
        
        if (sensorValue > sensorHigh) {
            sensorHigh = sensorValue;
        }
        
        if (sensorValue < sensorLow) {
            sensorLow = sensorValue;
        }
    }
    
    digitalWrite(ledPin, LOW);
    lcd.init();
    lcd.print("value ");
    lcd.backlight();
}

void loop() {
    sensorValue = analogRead(A0);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    tone(8, pitch, 20);
    
    //display
    lcd.setCursor(6, 0);
    lcd.print(sensorValue);
    delay(10);
}

