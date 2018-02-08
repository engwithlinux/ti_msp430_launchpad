
// includes:
#include <msp430.h>


void delay_ms(unsigned short delay);



int main(void)
{
  	// Disable Watchdog Timer
	WDTCTL = WDTPW + WDTHOLD;


	// Set Port 1 to all outputs
 	P1DIR |= 0xFF; 
   	

	// Infinite Loop
	while(1) {
		
		// Set all P1 outputs low
		P1OUT = 0x00; 

		// Delay for about a second
		delay_ms(500);

		// Set all P1 outputs high
		P1OUT = 0xFF; 

		// Delay for about a second
		delay_ms(500);
	}
}

void delay_ms(unsigned short delay) 
{
	unsigned short i = 0;
	
	for (i = 0; i < delay; ++i) {
		// Aproximetly a 1 millisecond delay
		__delay_cycles(1048);
	}
}




