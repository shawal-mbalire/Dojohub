#define pred A4
#define pgreen A5
#define redPin 3
#define greenPin 6

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pred, INPUT);
  pinMode(pgreen, INPUT);
  Serial.begin(9600);
}
void loop(){
  int red=analogRead(pred);
  int green=analogRead(pgreen);
  Serial.println(red);
  Serial.println(green);
  Serial.println(' ');

  int rednew = map(red, 635, 1023, 0, 255);
  int greennew = map(green, 635, 1023, 0, 255);


  analogWrite(redPin, rednew);
  analogWrite(greenPin, greennew);
  delay(1000);
}