

# define PORTB *((volatile unsigned char*)0x25)
# define DDRB *((volatile unsigned char*)0x24)

int main(void){
    DDRB |= 0b00100000;    
    while (1)
    {
        PORTB |= 0b00100000;
        for (long i = 0; i < 1000000; i++)
        {
           PORTB &= 0b11011111;
        }

        PORTB &= 0b11011111;        
        for (long i = 0; i < 1000000; i++)
        {
            PORTB |= 0b00100000;
        }
    }
}


