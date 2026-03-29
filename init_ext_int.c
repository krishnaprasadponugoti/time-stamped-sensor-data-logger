/*-------------------------------------------------------------------
File    : init_ext_int.c
Purpose : Source file for external interrupt (EINT0) configuration.
          Handles initialization of interrupt and ISR for switch press
          to trigger edit/menu mode.
-------------------------------------------------------------------*/

#include <lpc21xx.h>
#include "init_ext_int.h"

//-----------------------------------------------------------
// Function: init_int
// Purpose : Initializes external interrupt (EINT0)
//           - Configures pin function
//           - Enables interrupt in VIC
//           - Sets ISR vector address
//           - Configures edge triggering
//-----------------------------------------------------------
void init_int(void)
{
	//-------------------------------------------------------
	// Configure pin for EINT0 function
	//-------------------------------------------------------
	PINSEL1 = PINSEL1 & ~(3 << 0);   // Clear pin function bits
	PINSEL1 = PINSEL1 |  (1 << 0);   // Set pin as EINT0

	//-------------------------------------------------------
	// Enable interrupt in VIC (Vectored Interrupt Controller)
	//-------------------------------------------------------
	VICIntEnable = 1 << EXT_INT0_CH;         // Enable EINT0 interrupt
	VICVectCntl0 = (1 << 5) | EXT_INT0_CH;   // Enable slot and assign channel
	VICVectAddr0 = (unsigned int)switch_pressed; // Set ISR address

	//-------------------------------------------------------
	// Configure interrupt triggering mode
	//-------------------------------------------------------
	EXTMODE  = 1 << 0;   // Edge-triggered mode for EINT0
	EXTPOLAR = 0 << 0;   // Falling edge trigger (button press)
}

//-----------------------------------------------------------
// Function: switch_pressed
// Purpose : Interrupt Service Routine (ISR) for EINT0
//           - Clears interrupt flag
//           - Sets global flag to enter edit mode
//-----------------------------------------------------------
void switch_pressed(void) __irq
{
	//-------------------------------------------------------
	// Clear interrupt flag
	//-------------------------------------------------------
	EXTINT = 1 << 0;

	//-------------------------------------------------------
	// Set switch flag for main loop
	//-------------------------------------------------------
	pressed = 1;

	//-------------------------------------------------------
	// Acknowledge interrupt to VIC
	//-------------------------------------------------------
	VICVectAddr = 0;
}
