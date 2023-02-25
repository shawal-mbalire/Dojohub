/**********************************************************************
 * *********************************************************************
 * Shawal Mbalire
 * Dojohub Hardware course
 * Project 2 
 * Timeers and interupts
*************************************************************************
*************************************************************************/

#define ledPin 3
#define pushPin 2

int ledToggle = LOW;

void setup() {
  digitalWrite(ledPin, 1);
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(pushPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pushPin), blink, CHANGE);
}

void blink(){
  ledToggle=!ledToggle;
  digitalWrite(ledPin, ledToggle); 
}
void loop() {
  // put your main code here, to run repeatedly:
 
}
