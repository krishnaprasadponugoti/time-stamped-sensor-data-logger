/*-------------------------------------------------------------------
File    : init_ext_int.h
Purpose : Header file for external interrupt (EINT0) configuration.
          Defines macros and declarations for switch-based interrupt
          handling used to enter edit/menu mode.
-------------------------------------------------------------------*/

#include <lpc21xx.h>

/*-----------------------------------------------------------
Macro Definitions
Purpose : Define pin and interrupt channel for external switch
-----------------------------------------------------------*/
#define EXT_INT0_PIN 16   // Pin number used for external interrupt (EINT0)
#define EXT_INT0_CH  14   // Corresponding channel/function select value

/*-----------------------------------------------------------
Type Definition
Purpose : Define a volatile type for switch flag shared between
          ISR and main program
-----------------------------------------------------------*/
typedef volatile int sw;

/*-----------------------------------------------------------
External Variable Declaration
Purpose : Flag set by interrupt when switch is pressed
-----------------------------------------------------------*/
extern sw pressed;

/*-----------------------------------------------------------
Function Declarations
-----------------------------------------------------------*/

//-----------------------------------------------------------
// Function: init_int
// Purpose : Initializes external interrupt (EINT0)
//           Configures pin, edge triggering, and enables ISR
//-----------------------------------------------------------
void init_int(void);

//-----------------------------------------------------------
// Function: switch_pressed
// Purpose : Interrupt Service Routine (ISR) for external switch
//           Sets flag when interrupt is triggered
//-----------------------------------------------------------
void switch_pressed(void) __irq;
