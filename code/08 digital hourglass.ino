#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 1000;

void setup() {
    lcd_1.begin(16, 2);
    lcd_1.print("timee ");
    lcd_1.setBacklight(1);

    for(int x = 2;x<8;x++){
        pinMode(x, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}

void loop(){
    unsigned long currentTime = millis();
    if(currentTime - previousTime > interval) {
        previousTime = currentTime;
        digitalWrite(led, HIGH);
        led++;
        if(led == 7){}
    }
    switchState = digitalRead(switchPin);
    if(switchState != prevSwitchState){
        for(int x = 2;x<8;x++){
            digitalWrite(x, LOW);
        }
        led = 2;
        previousTime = currentTime;
    }
    prevSwitchState = switchState;

    lcd_1.setCursor(6, 0);
    lcd_1.print(currentTime);
}


