const int soilPin = A0;  

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(soilPin);  // 0~1023
  int moisturePercent = map(raw, 1023, 300, 0, 100);

  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Origin: ");
  Serial.print(raw);
  Serial.print("  Humidity: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(1000);
}