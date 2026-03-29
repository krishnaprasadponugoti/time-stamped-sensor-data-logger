/*-------------------------------------------------------------------
File    : defines_adc.h
Purpose : Macro definitions for ADC configuration and clock setup
          for LPC21xx microcontroller.
-------------------------------------------------------------------*/

#include<lpc21xx.h>

//-----------------------------------------------------------
// System Clock Definitions
//-----------------------------------------------------------
#define FOSC 12000000        // Oscillator frequency (12 MHz)
#define CCLK (5*FOSC)        // CPU clock after PLL multiplication
#define PCLK (CCLK/4)        // Peripheral clock frequency
#define ADCCLK 3000000       // ADC clock (recommended max ~4.5 MHz)
#define CLKDIV ((PCLK/ADCCLK)-1) // Divider to generate ADC clock

//-----------------------------------------------------------
// ADCR (ADC Control Register) Bit Positions
//-----------------------------------------------------------
#define CLKDIV_BITS 8        // Starting bit position for CLKDIV field
#define PDN 21               // Power control bit (1 = ADC ON)
#define START 24             // Start conversion control bits
#define BURST 16             // Burst mode enable bit

//-----------------------------------------------------------
// ADDR (ADC Data Register) Bit Positions
//-----------------------------------------------------------
#define RESULT 6             // Starting bit position of ADC result
#define DONE 31              // Conversion complete flag
#define OVERRUN 30           // Overrun flag (new data lost)

//-----------------------------------------------------------
// Analog Input Pin Definitions
//-----------------------------------------------------------
#define AIN0 27              // Analog input channel 0 pin
#define AIN1 28              // Analog input channel 1 pin
#define AIN2 29              // Analog input channel 2 pin
#define AIN3 30              // Analog input channel 3 pin

//-----------------------------------------------------------
// Channel Selection Bit Positions
//-----------------------------------------------------------
#define AIN_BIT_START 27     // Starting bit position for analog pin select
#define CH0 0                // ADC channel 0
#define CH1 1                // ADC channel 1
#define CH2 2                // ADC channel 2
#define CH3 3                // ADC channel 3
