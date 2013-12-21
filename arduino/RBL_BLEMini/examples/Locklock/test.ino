/*

Copyright (c) 2012, 2013 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include <ble_mini.h>
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
  BLEMini_begin(57600);
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
if ( BLEMini_available() > 0 ){
int command = BLEMini_read();
unsigned char result;


if(command==1){
  digitalWrite(led, HIGH);
  result = 'O';
  BLEMini_write(result);
  state = 1;
  analogWrite(P, 500); //rotates motor
  digitalWrite(N, LOW);    // set the Pin motorPin2 LOW
  delay(1000);
  analogWrite(P, LOW);

}
if(command==2){
  digitalWrite(led, LOW);
  result = 'F';  
  BLEMini_write(result);
  analogWrite(N, 500); //rotates motor
  digitalWrite(P, LOW);    // set the Pin motorPin2 LOW
  state = 2;
  delay(1000);
  analogWrite(N, LOW);

}

if(command==3){
  digitalWrite(led, LOW);
  result = 'S';
  state = 3;
  digitalWrite(P, LOW);
  digitalWrite(N, LOW);
  BLEMini_write(result);

}

}
  

  delay(100);
}

