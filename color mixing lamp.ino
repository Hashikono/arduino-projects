//PORTS: MAIN LED | SENSOR | REGULAR LED
const int red[] = {11,A2,3};
const int green[] = {9,A1,5};
const int blue[] = {10,A0,6};

int r_value = 0;
int g_value = 0;
int b_value = 0;

int r_sensor = 0;
int g_sensor = 0;
int b_sensor = 0;

void setup() {
    Serial.begin(9600);

    pinMode(red[0], OUTPUT);
    pinMode(red[2], OUTPUT);
    pinMode(green[0], OUTPUT);
    pinMode(green[2], OUTPUT);
    pinMode(blue[0], OUTPUT);
    pinMode(blue[2], OUTPUT);
}

void loop() {
    r_sensor = analogRead(red[1]);
    delay(5);
    g_sensor = analogRead(green[1]);
    delay(5);
    b_sensor = analogRead(blue[1]);

    Serial.print("RAW Sensor Values \t red: ");
    Serial.print(r_sensor);
    Serial.print("\t green: ");
    Serial.print(g_sensor);
    Serial.print("\t blue: ");
    Serial.print(b_sensor);

    r_value = r_sensor/4;
    g_value = g_sensor/4;
    b_value = b_sensor/4;

    Serial.print("MAPPED Sensor values \t red: ");
    Serial.print(r_value);
    Serial.print("\t green: ");
    Serial.print(g_value);
    Serial.print("\t blue: ");
    Serial.print(b_value);

    analogWrite(red[0], r_value);
    analogWrite(red[2], r_value);
    analogWrite(green[0], g_value);
    analogWrite(green[2], g_value);
    analogWrite(blue[0], b_value);
    analogWrite(blue[2], b_value);
}


