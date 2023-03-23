#include <SoftwareSerial.h>
SoftwareSerial softSerial(10, 11);
char ip;
void setup()  
{
  softSerial.begin(9600);
} 
void loop()  
{ 
  if (softSerial.available())
  {
    ip=softSerial.read();
    softSerial.print(ip);
  }
}
