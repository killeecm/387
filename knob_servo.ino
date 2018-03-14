/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservomid;  // create servo object to control a servo
Servo myservobottom;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;  // analog pin used to connect the potentiometer
int potpin2 = 2;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int val1;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservomid.attach(10);  // attaches the servo on pin 10 to the servo object
  myservobottom.attach(11);  // attaches the servo on pin 11 to the servo object
}

void loop() {  
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  myservomid.write(val1);                  // sets the servo position according to the scaled value
  myservobottom.write(val2);                 // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
