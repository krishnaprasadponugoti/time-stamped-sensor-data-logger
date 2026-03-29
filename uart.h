/*-------------------------------------------------------------------
File    : uart.h
Purpose : Function prototypes for UART communication.
          Provides initialization, transmission, reception,
          and utility functions for sending data over serial.
-------------------------------------------------------------------*/

//-----------------------------------------------------------
// Function: inituart
// Purpose : Initializes UART for serial communication
//-----------------------------------------------------------
void inituart(void);

//-----------------------------------------------------------
// Function: Txuart
// Purpose : Transmits a single character over UART
//-----------------------------------------------------------
void Txuart(unsigned char);

//-----------------------------------------------------------
// Function: Rxuart
// Purpose : Receives a single character from UART
//-----------------------------------------------------------
unsigned char Rxuart(void);

//-----------------------------------------------------------
// Function: uartTxstring
// Purpose : Transmits a null-terminated string over UART
//-----------------------------------------------------------
void uartTxstring(char *);

//-----------------------------------------------------------
// Function: Txint
// Purpose : Converts integer to string and transmits via UART
//-----------------------------------------------------------
void Txint(int);

//-----------------------------------------------------------
// Function: Txfloat
// Purpose : Converts float to string and transmits via UART
//-----------------------------------------------------------
void Txfloat(float);
