#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int notes[] = {262,294,330,349};

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.print("notes ");
    lcd.backlight();
}

void loop() {
    int keyVal = analogRead(A0);
    Serial.println(keyVal);
    lcd.setCursor(6, 0);

    if (keyVal == 1023){
        tone(8, notes[0]);
        lcd.print(notes[0]);
    } else if (keyVal >= 990 && keyVal <= 1010){
        tone(8, notes[1]);
        lcd.print(notes[1]);
    } else if (keyVal >= 505 && keyVal <= 515){
        tone(8, notes[2]);
        lcd.print(notes[2]);
    } else if (keyVal >= 5 && keyVal <= 10){
        tone(8, notes[3]);
        lcd.print(notes[3]);
    } else{
        noTone(8);
    }
}