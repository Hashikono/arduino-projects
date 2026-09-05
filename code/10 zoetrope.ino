const int controlPin1 = 2; 
const int controlPin2 = 3; 
const int enablePin = 9; 
const int directionSwitchPin = 4; 
const int onOffSwitchStateSwitchPin = 5; 
const int potPin = A0; 

int onOffSwitchState = 0; 
int previousOnOffSwitchState = 0; 
int directionSwitchState = 0; 
int previousDirectionSwitchState = 0; 

int motorEnabled = 0; 
int motorSpeed = 0; 
int motorDirection = 1; 

void setup() { 
  pinMode(directionSwitchPin, INPUT); 
  pinMode(onOffSwitchStateSwitchPin, INPUT); 
  pinMode(controlPin1, OUTPUT); 
  pinMode(controlPin2, OUTPUT); 
  pinMode(enablePin, OUTPUT); 
  digitalWrite(enablePin, LOW); 
} 

void loop() { 
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin); 
  delay(1); 
  directionSwitchState = digitalRead(directionSwitchPin); 
  motorSpeed = analogRead(potPin) / 4; 

  // --- ADDED: On/Off Switch Logic ---
  if (onOffSwitchState != previousOnOffSwitchState) { 
    if (onOffSwitchState == HIGH) { 
      motorEnabled = !motorEnabled; // Toggle motor state on button press
    } 
  } 

  // Direction Switch Logic
  if (directionSwitchState != previousDirectionSwitchState) { 
    if (directionSwitchState == HIGH) { 
      motorDirection = !motorDirection; 
    } 
  } 

  // Set Motor Direction
  if (motorDirection == 1) { 
    digitalWrite(controlPin1, HIGH); 
    digitalWrite(controlPin2, LOW); 
  } else { 
    digitalWrite(controlPin1, LOW); 
    digitalWrite(controlPin2, HIGH); 
  } 

  // Set Motor Speed / Enable
  if (motorEnabled == 1) { 
    analogWrite(enablePin, motorSpeed); 
  } else { 
    analogWrite(enablePin, 0); 
  } 

  // Save current states for the next loop iteration
  previousDirectionSwitchState = directionSwitchState; 
  previousOnOffSwitchState = onOffSwitchState; 
}
