/*
- left: A0,1,2
- right: A3,4,5
- left led: 10
- right led: 11
- piezo: 3
*/

//sensors
int 0_value;
int 1_value;
int 2_value;
int 3_value;
int 4_value;
int 5_value;

//values
int s_low = 1023;
int s_high = 0;

void setup() {
	pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(3, OUTPUT);
    while(millis() < 5000){
        0_value = analogRead(A0);
        1_value = analogRead(A1);
        2_value = analogRead(A2);
        3_value = analogRead(A3);
        4_value = analogRead(A4);
        5_value = analogRead(A5);
    }
}

