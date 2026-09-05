/*
Using delay() pauses the entire program, preventing it 
from reading buttons or updating other components. 

The millis() approach creates a timer that runs in the background, 
allowing the processor to keep executing code continuously.
*/

const int BUTTON = 9;
const int LED_BLINK = 10;
const int LED_STATUS = 11;

unsigned long last = 0;       // Stores the last time the LED updated
const long interval = 1000;   // Interval at which to blink (in milliseconds)
bool blinkState = false;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_BLINK, OUTPUT);
  pinMode(LED_STATUS, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // --- NON-BLOCKING TIMER ---
  // Check if the difference between current time and last recorded time
  // is greater than or equal to your desired interval.
  if (millis() - last >= interval) {
    last = millis(); // Save the current time for the next comparison
    
    Serial.print(digitalRead(BUTTON));
    blinkState = !blinkState; // Toggle the LED state
    digitalWrite(LED_BLINK, blinkState);
  }

  // --- RUNS CONTINUOUSLY ---
  // This status LED responds instantly to button presses because there is no delay() blocking the loop.
  digitalWrite(LED_STATUS, digitalRead(BUTTON) == LOW);
}
