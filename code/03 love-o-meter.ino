const int sensorPin = A0;
float base = 20.0;
int switch1 = digitalRead(2);

/*
- piezo is @ 6
- switch is @ 2
- LEDs @ 3-5
- temp sensor @ A0

*/

float calibration(){
    float s = analogRead(sensorPin);
    float v = (s/1024)*5;
    float t = (v - 0.5)*100;
    return t;
}


void setup(){
    Serial.begin(9600);
    for (int i = 3; i < 6; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i,LOW);
    }
    pinMode(2, INPUT);
    pinMode(A0, INPUT);
    base = calibration();
}

void loop(){
    // BUTTON PRESS
    switch1 = digitalRead(2);
    if (switch1 == HIGH){
        base = calibration();
    }

    // STANDARD VALUE
    float sensorVal = analogRead(sensorPin);
    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);

    // ADC reading to voltage
    float voltage = (sensorVal/1024)*5;
    Serial.print(", Volts: ");
    Serial.print(voltage);

    // Voltage temp to Degrees
    float temp = (voltage - 0.5)*100;
    Serial.print(", Degrees C: ");
    Serial.print(temp);
    Serial.println("-");

    // TURNING ON LIGHTS
    if (temp < base + 2){
        for (int i = 3; i < 6; i++){
            digitalWrite(i, LOW);
        }
    } else if (temp >= base + 2 && temp < base + 4){
        for (int i = 3; i < 6; i++){
            digitalWrite(i, LOW);
        }
        digitalWrite(3, HIGH);
    } else if (temp >= base + 4 && temp < base + 6){
        for (int i = 3; i < 6; i++){
            digitalWrite(i, HIGH);
        }
        digitalWrite(5, LOW);
    } else if (temp >= base + 6){
        for (int i = 3; i < 6; i++){
            digitalWrite(i, HIGH);
        }
    }

    // Piezo
    int sound = temp-base;
    analogWrite(6, sound);

    delay (1);
}