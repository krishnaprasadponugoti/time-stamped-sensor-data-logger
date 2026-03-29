/*-------------------------------------------------------------------
File    : delay.h
Purpose : Function prototypes for software delay routines.
          Provides microsecond, millisecond, and second delays
          used across the project for timing and interfacing.
-------------------------------------------------------------------*/

//-----------------------------------------------------------
// Function: delay_us
// Purpose : Generates approximate delay in microseconds
//           (used for short timing requirements)
//-----------------------------------------------------------
void delay_us(unsigned int);

//-----------------------------------------------------------
// Function: delay_ms
// Purpose : Generates approximate delay in milliseconds
//           (commonly used for LCD and peripheral timing)
//-----------------------------------------------------------
void delay_ms(unsigned int);

//-----------------------------------------------------------
// Function: delay_s
// Purpose : Generates delay in seconds
//           (used for long duration delays if required)
//-----------------------------------------------------------
void delay_s(unsigned int);
