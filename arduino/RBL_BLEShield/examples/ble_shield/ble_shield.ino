#include <ble_shield.h>
#include <boards.h>
#include <Servo.h>

#define P 5
#define N 6
Servo myservo;
unsigned long currentMillis;        // store the current value from millis()
unsigned long previousMillis;       // for comparison with currentMillis
int samplingInterval = 250;          // how often to run the main loop (in ms)
int led = 13;
int time = 0;
int state = 0;
void setup()
{
	ble_begin();
	Serial.begin(57600);
	//  pinMode(DIGITAL_OUT_PIN, OUTPUT);
	//  pinMode(DIGITAL_IN_PIN, INPUT);
	//  
	//  // Default to internally pull high, change it if you need
	//  digitalWrite(DIGITAL_IN_PIN, HIGH);
	//digitalWrite(DIGITAL_IN_PIN, LOW);
	pinMode(led, OUTPUT);
	pinMode(P, OUTPUT);
	pinMode(N, OUTPUT);
}

void loop()
{
	//  static boolean analog_enabled = false;
	//  static byte old_state = LOW;
	//Serial.println(BLEMini_available(),DEC);
	//if (time==0){
	//  digitalWrite(P, LOW);
	//  digitalWrite(N, LOW);
	//}else{
	//  time = time - 1;
	//}
	if (ble_available() > 0) {
		int command = ble_read();
		unsigned char result;


		if (command == 1) {
			digitalWrite(led, HIGH);
			result = 'O';
			ble_write(result);
			state = 1;
			analogWrite(P, 500); //rotates motor
			digitalWrite(N, LOW);    // set the Pin motorPin2 LOW
			delay(1000);
			analogWrite(P, LOW);
		}

		if (command == 2) {
			digitalWrite(led, LOW);
			result = 'F';
			ble_write(result);
			analogWrite(N, 500); //rotates motor
			digitalWrite(P, LOW);    // set the Pin motorPin2 LOW
			state = 2;
			delay(1000);
			analogWrite(N, LOW);

		}

		if(command == 3){
			digitalWrite(led, LOW);
			result = 'S';
			state = 3;
			digitalWrite(P, LOW);
			digitalWrite(N, LOW);
			ble_write(result);
		}
	}
	delay(100);
}

