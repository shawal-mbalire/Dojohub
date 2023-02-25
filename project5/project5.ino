#include <Servo.h>
#include <HCSR04.h>
#define servoPin 10
#define trigPin 7
#define echoPin 6

Servo myservo;  // create servo object to control a servo
HCSR04 hc(trigPin,echoPin);

int pos = 0;    // variable to store the servo position
bool isopen= true;
void setup() {
  myservo.attach(servoPin);  // attaches the servo on SERVOpin to the servo object  
  Serial.begin(9600);
}

void loop() {

  float distance=hc.dist();
  Serial.println(distance);
  delay(100);
  
  if (!isopen && distance<20){
   for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    isopen=true;
  }
  else if (isopen && distance>20) {
     for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    isopen=false;
  }
  
}
