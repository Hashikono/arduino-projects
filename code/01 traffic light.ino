
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  int x[] = {11,13,13,12,12,11};
  int tim[] = {3000,3000,1000};
  for (int i = 0; i < 3; i++){
    digitalWrite(x[2*i], LOW);
    digitalWrite(x[2*i+1], HIGH);
    delay(tim[i]);
  }
}