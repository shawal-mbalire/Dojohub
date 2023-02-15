// led pins 
#define ledRed 2
#define ledBlue 3
#define ledYellow 4
#define ledGreen 5

#define leftPush 6
#define rightPush 7

void left_right(){
  //RBYG on left push
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,HIGH);
  delay(500);
  
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,HIGH);
  digitalWrite(ledRed,LOW);
  delay(500);

  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,HIGH);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,LOW);
  delay(500);

  digitalWrite(ledGreen,HIGH);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,LOW);
  delay(500); 

  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,LOW); 
}

void right_left(){
  //GYBR on right push
  digitalWrite(ledGreen,HIGH);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,LOW);
  delay(500);

  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,HIGH);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,LOW);
  delay(500);
  
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,HIGH);
  digitalWrite(ledRed,LOW);
  delay(500);

  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,HIGH);
  delay(500);

  digitalWrite(ledGreen,LOW);
  digitalWrite(ledYellow,LOW);
  digitalWrite(ledBlue,LOW);
  digitalWrite(ledRed,LOW);
}

void setup() {
  // put your setup code here, to run once:
  digitalWrite(ledGreen,LOW);
  delay(500);
  digitalWrite(ledYellow,LOW);
  delay(500);
  digitalWrite(ledBlue,LOW);
  delay(500);
  digitalWrite(ledRed,LOW);
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(leftPush) == 1) {
    left_right();
  }
  else if (digitalRead(rightPush) == 1) {
    right_left();
  }

}
