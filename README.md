# Time-Stamped Sensor Data Logger

## Objective

A Time-Stamped Sensor Data Logger is a system that continuously records sensor readings along with accurate date and time information for later analysis. It ensures traceability, fault analysis, and historical data tracking, which are essential in industrial and research applications.

---

## Description

This project implements a temperature monitoring and logging system using the LPC2148 microcontroller.

The system reads temperature data from an LM35 sensor using the ADC and combines it with real-time date and time obtained from the on-chip RTC. The collected data is displayed on a 16x2 LCD for real-time monitoring and transmitted to a PC via UART for logging and analysis.

Additionally, the system includes an alert mechanism that triggers when the temperature exceeds a predefined threshold.
