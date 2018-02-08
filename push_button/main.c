
// includes:
#include <msp430.h>

#define BUTTON_BIT        0x08
#define RED_LED_BIT       0x01
#define GREEN_LED_BIT     0x40


int main(void)
{

  	// Disable Watchdog Timer
	WDTCTL = WDTPW + WDTHOLD;


	// Set Port 1 to all outputs
 	P1DIR = 0xFF; 
	P1OUT = 0x00;

	// Setup Button
	P1DIR &= ~BUTTON_BIT;  // Set button to be an input
	P1REN |= BUTTON_BIT;   // Enable internal resister
	P1OUT |= BUTTON_BIT;   // Enable pull-up resister


	// Infinite Loop
	while(1) {

		// If button is not pressed
		if ((P1IN & BUTTON_BIT) == BUTTON_BIT) {
			P1OUT |= GREEN_LED_BIT;   // Light green LED
			P1OUT &= ~RED_LED_BIT;    // Turn off red LED
		}
		else {
			P1OUT |= RED_LED_BIT;     // Light red LED
			P1OUT &= ~GREEN_LED_BIT;  // Turn off green LED 	
		}
	}
}






