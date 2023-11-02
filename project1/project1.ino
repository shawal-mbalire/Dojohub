/**********************************************************************
 * *********************************************************************
 * Shawal Mbalire
 * Dojohub Hardware course
 * Project 1 
 * 
*************************************************************************
*************************************************************************/
#define port_D               *(( volatile byte*) 0x2B)
#define direction_Register_D *(( volatile byte*) 0x2A)
#define pin_D                *(( volatile byte*) 0x29)
// #define port_C               *(( volatile byte*) 0x28)
// #define direction_Register_C *(( volatile byte*) 0x27)
// #define pin_C                *(( volatile byte*) 0x26)
// #define port_B               *(( volatile byte*) 0x25)
// #define direction_Register_B *(( volatile byte*) 0x24)
// #define pin_B                *(( volatile byte*) 0x23)
#define tim 2000000

int main( void ) 
{
  direction_Register_D  = B01111000; // set pins 3 to 6 as output and 2,7 input // 76543210
  port_D                = B00000000; // initialise everything as low // 76543210

  while (1)
  {
    // put your main code here, to run repeatedly:
    if (pin_D & B00000100)
    {
      for (long i=0; i < (tim); i++)port_D = B01000000;// 76543210
      for (long i=0; i < (tim); i++)port_D = B00100000;// 76543210
      for (long i=0; i < (tim); i++)port_D = B00010000;// 76543210
      for (long i=0; i < (tim); i++)port_D = B00001000;// 76543210
      for (long i=0; i < (tim); i++)port_D = B00000100;// 76543210
    }
    port_D                = B10000100;

    if (pin_D & B10000000)
    {
      for (long i=0; i < (tim); i++)port_D = B00000100;// 76543210
      for (long i=0; i < (tim); i++)port_D = B00001000;// 76543210
      for (long i=0; i < (tim); i++)port_D = B00010000;// 76543210
      for (long i=0; i < (tim); i++)port_D = B00100000;// 76543210
    }
    port_D                = B10000100;
  }

  return 0;
}

