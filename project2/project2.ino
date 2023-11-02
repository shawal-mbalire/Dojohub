/**********************************************************************
 * *********************************************************************
 * Shawal Mbalire
 * Dojohub Hardware course
 * Project 2 
 * Timers and interupts
*************************************************************************
*************************************************************************/
#define port_D               *(( volatile byte*) 0x2B)
#define direction_Register_D *(( volatile byte*) 0x2A)
#define pin_D                *(( volatile byte*) 0x29)
#define port_change_mask_2   *(( volatile byte*) 0x6D)
#define port_change_interupt_control   *(( volatile byte*) 0x68) // 3 bit 1 for a mask

int ledToggle=0;
bool D2_state = LOW;
bool D5_state = LOW;

int main() {

  
  port_change_interupt_control |= B00000100; // pcmsk2 pcmsk1 pcmsk0
  port_change_mask_2           |= B00000100; // 76543210

  
  while(1)
  {
    asm("");
  }
  return 0;
}

ISR (PCINT2_vect) 
{
  if((pin_D & B00000100) && D2_state){
   	port_D = !port_D
	  //Pin D4 triggered the ISR
  }
  else if((pin_D & B00000100) && !D2_state){
   	port_D ^= (1<<2);
  }
   
   
  if((pin_D & B00100000) && D5_state){
   	port_D = !port_D
	  //Pin D5 triggered the ISR
  }
  else if((pin_D & B00100000) && !D5_state){
   	port_D = port_D;
  }
}