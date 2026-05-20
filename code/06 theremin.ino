/*
- left: A0,A1,A2
- right: A3,A4,A5
- left led: 10
- right led: 11
- piezo: 3
*/

//sensors
int x0_value = 0;
int x1_value = 0;
int x2_value = 0;
int x3_value = 0;
int x4_value = 0;
int x5_value = 0;

int sensorLow = 1023;
int sensorHigh = 0;

float left;
float right;

//values
int s_low = 1023;
int s_high = 0;

float sValue(){
    x0_value = analogRead(A0);
    x1_value = analogRead(A1);
    x2_value = analogRead(A2);
    x3_value = analogRead(A3);
    x4_value = analogRead(A4);
    x5_value = analogRead(A5);

    left = (x0_value + x1_value + x2_value)/3;
    right = (x3_value + x4_value + x5_value)/3;
    return (left+right)/2;
}

void setup() {
  	Serial.begin(9600);
	pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(3, OUTPUT);
    while(millis() < 500){
        x0_value = analogRead(A0);
        x1_value = analogRead(A1);
        x2_value = analogRead(A2);
        x3_value = analogRead(A3);
        x4_value = analogRead(A4);
        x5_value = analogRead(A5);
    }

    //combination
    left = (x0_value + x1_value + x2_value)/3;
    right = (x3_value + x4_value + x5_value)/3;
    float sensorValue = (left+right)/2;

    //don't know
    if (sensorValue > sensorHigh) {
        sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
        sensorLow = sensorValue;
    }

    analogWrite(10, left/500);
    analogWrite(11, right/500);
  	Serial.println(analogRead(A0));
    Serial.println(analogRead(A1));
    Serial.println(analogRead(A2));
    Serial.println(analogRead(A3));
    Serial.println(analogRead(A4));
    Serial.println(analogRead(A5));
    Serial.println(right);
    Serial.print(left);
}

void loop() {
    float sens = sValue();
    int pitch = map(sens,sensorLow,sensorHigh, 50, 4000);
    tone(3, pitch,20);
    analogWrite(10, left/500);
    analogWrite(11, right/500);
    delay(10);
    Serial.println(analogRead(A0));
    Serial.println(analogRead(A1));
    Serial.println(analogRead(A2));
    Serial.println(analogRead(A3));
    Serial.println(analogRead(A4));
    Serial.println(analogRead(A5));
    Serial.println(right);
    Serial.print(left);
}

