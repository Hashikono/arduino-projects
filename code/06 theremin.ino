#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

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
    lcd_1.begin(16, 2);
    lcd_1.print("value ");
    lcd_1.setBacklight(1);
}

void loop() {
    sensorValue = analogRead(A0);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    tone(8, pitch, 20);
    
    //display
    lcd_1.setCursor(6, 0);
    lcd_1.print(sensorValue);
    delay(10);
}

