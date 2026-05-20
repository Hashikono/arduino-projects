#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

int notes[] = {262,294,330,349};

void setup() {
    Serial.begin(9600);
    lcd_1.begin(16, 2);
    lcd_1.print("notes ");
    lcd_1.setBacklight(1);
}

void loop() {
    int keyVal = analogRead(A0);
    Serial.println(keyVal);
    lcd_1.setCursor(6, 0);

    if (keyVal == 1023){
        tone(8, notes[0]);
        lcd_1.print(notes[0]);
    } else if (keyVal >= 990 && keyVal <= 1010){
        tone(8, notes[1]);
        lcd_1.print(notes[1]);
    } else if (keyVal >= 505 && keyVal <= 515){
        tone(8, notes[2]);
        lcd_1.print(notes[2]);
    } else if (keyVal >= 5 && keyVal <= 10){
        tone(8, notes[3]);
        lcd_1.print(notes[3]);
    } else{
        noTone(8);
    }
}