#include <Servo.h>
Servo myServo;
int const potentiometer = A0;
int p_value;
int angle;

//modifications
int switch1 = 0;
int toggle = 0;

void setup()
{
    myServo.attach(9);
    Serial.begin(9600);
    pinMode(6, OUTPUT);
}

void loop()
{
    switch1 = digitalRead(2);
    p_value = analogRead(potentiometer);
    
    //TOGGLE SOUND
    if (switch1 == HIGH){
        if (toggle == 0){
            toggle = 1;
            delay(100);
        }
        else {
            toggle = 0;
            delay(100);
        }
    }

    //Regular mood cue function
    Serial.print("Potentiometer value: ");
    Serial.println(p_value);

    angle = map(p_value, 0, 1023, 0, 179);
    Serial.print("Angle: ");
    Serial.println(angle);

    myServo.write(angle);
    if (toggle == 1){
        analogWrite(6, angle/2);
        Serial.println("ON");
      
    } else {
     	analogWrite(6, 0);
        Serial.println("OFF");
    }
    delay(15);  
}