//---------------------- TINKERCAD ----------------------

// STANDARD IMPORTS
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
    // initialization function
    lcd_1.begin(16, 2);

    // printing
    lcd_1.print("hello world");
}

void loop()
{
    // sets cursor to the second row
    lcd_1.setCursor(0, 1);

    // backlight setting (off/on)
    lcd_1.setBacklight(0);
    lcd_1.setBacklight(1);
}


//---------------------- IN REAL LIFE ----------------------

// STANDARD IMPORTS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
    // initialization function
    lcd.init();

    // printing
    lcd.print("hello world");
}

void loop()
{
    // sets cursor to the first row
    lcd.setCursor(0, 0);
    
    // backlight setting (off/on)
    lcd.noBacklight();
    lcd.backlight();
}


