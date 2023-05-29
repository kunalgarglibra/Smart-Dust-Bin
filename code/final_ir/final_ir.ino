#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position


int sensor_pin =D3;
int ir_sensor =D5;

void setup() {
  myservo.attach(D4);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(ir_sensor, INPUT);
  pinMode(sensor_pin, INPUT);

}

void loop() {
  Serial.println(digitalRead(ir_sensor));
  if(digitalRead(ir_sensor) == HIGH)
  {
  if(digitalRead(sensor_pin) == LOW)
  {

    for (pos = 90; pos <= 180; pos += 1) 
    { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
    }
   
   for (pos = 180; pos >= 90; pos -= 1) 
   { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
   }
  
  }

   if(digitalRead(sensor_pin) == HIGH)
  
   {

    for (pos = 90; pos >= 0; pos -= 1) 
    { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
   }
  for (pos = 0; pos <= 90; pos += 1) { // goes from 180 degrees to 0 degrees
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    delay(15);
   }
  }
  else
  {int pos = 90;}
}
