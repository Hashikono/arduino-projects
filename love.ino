const int sensorPin = A0;
float base = 20.0;

/*
- piezo is @ A1
- switch is @ 2
- LEDs @ 3-5
- temp sensor @ A0

*/

void setup(){
    Serial.begin(9600);
    for (int i = 3; i < 5; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i,LOW);
    }
}

void void loop(){
    // STANDARD VALUE
    int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor Value: " + sensorVal);

    // ADC reading to voltage
    float voltage = (sensorVal/1024) * 5;
    Serial.print(", Volts: " + voltage);

    // Voltage temp to Degrees
    float temp = (voltage - 0.5)*100;
    Serial.print(", Degrees C: " + temp);


    // TURNING ON LIGHTS
    if (temp < base + 2){
        for (int i = 3; i < 5; i++){
            digitalWrite(i, LOW);
        }
    } else if (temp >= base + 2 && temp < base + 4){
        for (int i = 3; i < 5; i++){
            digitalWrite(i, LOW);
        }
        digitalWrite(3, HIGH);
    } else if (temp >= base + 4 && temp < base + 6){
        for (int i = 3; i < 5; i++){
            digitalWrite(i, HIGH);
        }
        digitalWrite(5, LOW);
    } else if (temp >= base + 6){
        for (int i = 3; i < 5; i++){
            digitalWrite(i, HIGH);
        }
    }
    delay (1);
}