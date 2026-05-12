// C++ code
//

int switch1 = 0;
int switch2 = 0;
int toggle = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
}

void loop()
{
  switch1 = digitalRead(2);
  switch2 = digitalRead(6);
  
  //UPDATED TOGGLE
  if (switch1 == HIGH){
    if (toggle == 0){
    	toggle = 1;
      	digitalWrite(3, HIGH);
    }
    else {
    	toggle = 0;
        digitalWrite(3, LOW);
    }
  }
  
  if (switch2 == LOW){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(1000);
  }
  else {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(200);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(200);
  }
}