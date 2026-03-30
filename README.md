# Time-Stamped Sensor Data Logger

## Objective

A Time-Stamped Sensor Data Logger is a system that continuously records sensor readings along with accurate date and time information for later analysis. It ensures traceability, fault analysis, and historical data tracking, which are essential in industrial and research applications.

---

## Description

This project implements a temperature monitoring and logging system using the LPC2148 microcontroller.

The system reads temperature data from an LM35 sensor using the ADC and combines it with real-time date and time obtained from the on-chip RTC. The collected data is displayed on a 16x2 LCD for real-time monitoring and transmitted to a PC via UART for logging and analysis.

Additionally, the system includes an alert mechanism that triggers when the temperature exceeds a predefined threshold.
---

## Working Principle

When powered on, the LPC2148 initializes all required peripherals including ADC, RTC, UART, LCD, keypad, and alert system.

- Temperature is continuously read from the LM35 sensor using ADC  
- Current time and date are obtained from the RTC  
- Data is formatted with timestamp  
- Displayed on LCD (real-time monitoring)  
- Sent to PC via UART (logging)  

If temperature exceeds the threshold:
- LED/Buzzer is activated  
- Alert message is transmitted  

The system runs continuously in an infinite loop ensuring real-time monitoring and logging.

---

## Features

- Real-time temperature monitoring using LM35  
- Time-stamped logging using RTC  
- LCD display for live data  
- UART communication for serial logging  
- Over-temperature alert (LED/Buzzer)  
- RTC editing via keypad  
- Adjustable temperature threshold  
---

## Hardware Used

- LPC2148 Microcontroller  
- LM35 Temperature Sensor  
- 16x2 LCD  
- Keypad  
- Switch  
- LED / Buzzer  
- MAX232  

---

## Software Used

- Embedded C  
- Keil uVision  
- Flash Magic  

---

## Output Format

### LCD Display

HH:MM:SS DAY  
DD/MM/YY  T: 32°C

### Serial Output


[INFO] Temp: 32.5°C @ 13:45:20 13/05/2025  
[ALERT] Temp: 47.3°C @ 14:10:55 13/05/2025  
