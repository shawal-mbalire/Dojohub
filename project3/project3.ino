/*
Shawal Mbalire
Dojo hub hardware course
Project3
*/

#define ldrPin A0
#define optoPin 2

void setup(){
  pinMode(ldrPin,INPUT);
  pinMode(optoPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(optoPin,HIGH);
}

void loop(){
  float value = analogRead(ldrPin);
  Serial.println(value);
  if (value>200) {
    digitalWrite(optoPin,LOW);
  }else if (value<200) {
    digitalWrite(optoPin,HIGH);
  }
}
