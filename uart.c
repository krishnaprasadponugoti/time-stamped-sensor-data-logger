/*-------------------------------------------------------------------
File    : uart.c
Purpose : Configure UART0 of LPC21xx for serial communication.
          Provides functions for transmitting characters,
          strings, integers, and floating-point values.
-------------------------------------------------------------------*/

#include <lpc21xx.h>   // LPC21xx register definitions
#include "uart.h"      // UART function prototypes

//-----------------------------------------------------------
// System clock definitions (used for baud rate calculation)
//-----------------------------------------------------------
#define FOSC 12000000        // External oscillator frequency = 12 MHz
#define CCLK (5 * FOSC)      // CPU clock frequency = 60 MHz (PLL)
#define PCLK (CCLK / 4)      // Peripheral clock = 15 MHz

//-----------------------------------------------------------
// Function: inituart
// Purpose :
//   - Configure UART0 pins (TXD0, RXD0)
//   - Set UART frame: 8-bit data, no parity, 1 stop bit
//   - Configure baud rate to 9600 bps
//-----------------------------------------------------------
void inituart(void)
{
	// Configure P0.0 (TXD0) and P0.1 (RXD0) for UART function
	PINSEL0 = (PINSEL0 & (~(0xF << 0))) | (5 << 0);

	// Set word length = 8 bits (DLAB = 0 initially)
	U0LCR |= 0x03;

	// Enable access to divisor latches (DLAB = 1)
	U0LCR |= (1 << 7);

	// Set baud rate divisor for 9600 bps
	// For PCLK = 15 MHz ? DLL = 97, DLM = 0
	U0DLL = 97;
	U0DLM = 0;

	// Disable divisor latch access (DLAB = 0)
	U0LCR &= ~(1 << 7);
}

//-----------------------------------------------------------
// Function: Txuart
// Purpose :
//   - Transmits a single character via UART0
//   - Waits until THR (Transmit Holding Register) is empty
//-----------------------------------------------------------
void Txuart(unsigned char val)
{
	U0THR = val;   // Load data into transmit register

	// Wait until THR is empty (ready for next transmission)
	while (((U0LSR >> 5) & 1) == 0);
}

//-----------------------------------------------------------
// Function: Rxuart
// Purpose :
//   - Waits until data is received
//   - Reads and returns received character
//-----------------------------------------------------------
unsigned char Rxuart(void)
{
	// Wait until data ready (RDR bit set)
	while (((U0LSR >> 0) & 1) == 0);

	return U0RBR;   // Return received byte
}

//-----------------------------------------------------------
// Function: uartTxstring
// Purpose :
//   - Sends a null-terminated string via UART
//   - Transmits one character at a time
//-----------------------------------------------------------
void uartTxstring(char *p)
{
	while (*p)
	{
		Txuart(*p);   // Send current character
		p++;          // Move to next character
	}
}

//-----------------------------------------------------------
// Function: Txfloat
// Purpose :
//   - Transmits floating-point value via UART
//   - Prints integer part and one digit after decimal
//-----------------------------------------------------------
void Txfloat(float num)
{
	int n, i;

	// Handle negative numbers
	if (num < 0)
	{
		Txuart('-');
		num = -num;
	}

	// Extract and print integer part
	n = num;
	Txint(n);

	Txuart('.');   // Print decimal point

	// Print one digit after decimal point
	for (i = 0; i < 1; i++)
	{
		num = num - n;   // Remove integer part
		num = num * 10;  // Shift next decimal digit
		n = num;
		Txuart(n + '0');
	}
}

//-----------------------------------------------------------
// Function: Txint
// Purpose :
//   - Converts integer to ASCII and transmits via UART
//   - Handles negative numbers and preserves zeros
//-----------------------------------------------------------
void Txint(int num)
{
	int zeros, rev = 0, temp;
	int num_length = 0, rev_length = 0;

	// Special case: number is zero
	if (num == 0)
	{
		Txuart('0');
		return;
	}

	// Handle negative numbers
	if (num < 0)
	{
		Txuart('-');
		num = -num;
	}

	// Reverse number and count digits
	temp = num;
	while (temp)
	{
		num_length++;
		rev = rev * 10 + (temp % 10);
		temp /= 10;
	}

	// Transmit digits in correct order
	temp = rev;
	while (temp)
	{
		rev_length++;
		Txuart((temp % 10) + '0');
		temp /= 10;
	}

	// Add missing leading zeros if required
	zeros = num_length - rev_length;
	while (zeros)
	{
		Txuart('0');
		zeros--;
	}
}
