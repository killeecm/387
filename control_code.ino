/*
 This code controls three servo motors using potentiometers. 
 Its main use is to control an arm that was 3D printed
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a the top servo of the arm
Servo myservomid;  // create servo object to control a the middle servo
Servo myservobottom;  // create servo object to control a the servo on the bottom of the arm

int potpin = 0;  // analog pin used to connect the potentiometer number one
int potpin1 = 1;  // analog pin used to connect the potentiometer number 2
int potpin2 = 2;  // analog pin used to connect the potentiometer number 3
int val;    // variable to read the value from the analog pin of potentiometer number one
int val1;    // variable to read the value from the analog pin of potentiometer number two
int val2;    // variable to read the value from the analog pin of potentiometer number three
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the top servo object
  myservomid.attach(10);  // attaches the servo on pin 10 to the middle servo object
  myservobottom.attach(11);  // attaches the servo on pin 11 to the bottom servo object
}

void loop() {  
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the top servo position according to the scaled value
  myservomid.write(val1);                  // sets the middle servo position according to the scaled value
  myservobottom.write(val2);                 // sets the bottom servo position according to the scaled value
  delay(15);                           // waits for the servo to get to the desired location. This also helps with the shaking of the motors.
}
