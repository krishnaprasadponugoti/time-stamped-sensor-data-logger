/*-------------------------------------------------------------------
File    : rtc_defines.h
Purpose : Macro definitions and function prototypes for RTC
          (Real-Time Clock) configuration and operation on LPC21xx.
-------------------------------------------------------------------*/

#include<lpc21xx.h>

//-----------------------------------------------------------
// System Clock Definitions (used for RTC calculation)
//-----------------------------------------------------------
#define FOSC 12000000            // Oscillator frequency (12 MHz)
#define CCLK (5*FOSC)            // CPU clock after PLL
#define PCLK (CCLK/4)            // Peripheral clock

//-----------------------------------------------------------
// RTC Prescaler Calculations
// Purpose : Generate 1-second time base using 32.768 kHz
//-----------------------------------------------------------
#define PRE_INT  ((PCLK/32768)-1)              // Integer part of prescaler
#define PRE_FRAC (PCLK-((PRE_INT+1)*32768))    // Fractional part

//-----------------------------------------------------------
// RTC Control Bits
//-----------------------------------------------------------
#define CLK_EN  0      // Clock Enable bit
#define CLK_RST 1      // Clock Reset bit
#define CLK_SRC 4      // Clock Source selection bit

//-----------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------

//-----------------------------------------------------------
// Function: setRTCtime
// Purpose : Set RTC time (hour, minute, second)
//-----------------------------------------------------------
void setRTCtime(int ,int ,int);

//-----------------------------------------------------------
// Function: setRTCdate
// Purpose : Set RTC date (day, month, year)
//-----------------------------------------------------------
void setRTCdate(int ,int ,int);

//-----------------------------------------------------------
// Function: initRTC
// Purpose : Initialize RTC with prescaler and enable clock
//-----------------------------------------------------------
void initRTC(void);

//-----------------------------------------------------------
// Function: readRTCtime
// Purpose : Read current time from RTC
//-----------------------------------------------------------
void readRTCtime(int *,int *,int *);

//-----------------------------------------------------------
// Function: readRTCdate
// Purpose : Read current date from RTC
//-----------------------------------------------------------
void readRTCdate(int *,int *,int *);

//-----------------------------------------------------------
// Function: readRTCdow
// Purpose : Read current day of week from RTC
//-----------------------------------------------------------
void readRTCdow(int *);

//-----------------------------------------------------------
// Function: setRTCdow
// Purpose : Set day of week in RTC
//-----------------------------------------------------------
void setRTCdow(int);
