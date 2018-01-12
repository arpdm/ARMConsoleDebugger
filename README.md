# ARMConsoleDebugger
Console module for debugging ARM embedded systems

  The ARM Console Debugger is collection of methods, software, and hardware. It is meant for implement a debugging system while designing embedded software/hardware. It provides multiple debugging and interfacing option easing the process of embedded system design. 

  The following items are included in this collection and each item will be explained in this document
  
  * Redirecting printf to UART 
  * Console terminal interface
  * Windows GUI software
  * Python software
  * Logic analyzers

## Required third-party tools

  * FTDI TTL-232
  * Console terminal (ex: RealTerm)

## Limitations with using UART for debugging purposes

  * It requires extra UART peripheral and two extra spare pins
  * Minimum clock speed needed for UART operation. This can be problematic for low-power applications. 
  * It is an intrusive way of debugging and its intrusiveness is not negligible for most applications. 
  * It requires extra code space

## UART Configuration

  In this example UART configuration is set as following.
  
  * Start bit: 1
  * Data bits: 8
  * Parity: None
  * Stop bit/s: 1
  * Baud Rate: 9600

Once the base is setup for UART communication, any of the modules in this collection can be used for debugging/interfacing purposes. 


## Redirecting printf to UART

Printf can be used to print debugging messages to the UART port. This is super useful for following the state of the firmware operation. Any software with serial communication can read the printf messages.

##Console terminal interface:

  With this feature, users can control the embedded system by both reading and writing. This is possible by adding a Console thread in the RTOS. Simply the thread will have a state machine for parsing user data and based on data provided, will perform specific functions. The console thread can also send feedback using printf function. The Console thread is designed to work in RTOS environment. 

  This code has few parts. The universal interrupt handler, global os objects, and the Console thread it self. This code has been developed in Keil uVision5 for STM32F0 MCU. However, it will work with other Cortex M microcontrollers with little modification on the driver side. 

## Python software

  Python is super useful and easy language. In worst case scenario of there is no terminal application or no console thread has been implemented in the firmware, with few lines of python code, it will be possible to monitor the print messages. For the serial communication in python code, pySerial library has been used.

This code is bare minimum, developers can build on top of this and user other features of pySerial. More information on pySerial can be found in the following links. 
  * https://petrimaki.com/2013/04/28/reading-arduino-serial-ports-in-windows-7/
  * http://pyserial.readthedocs.io/en/latest/shortintro.html 
  * https://pythonhosted.org/pyserial/
  * https://media.readthedocs.org/pdf/pyserial/latest/pyserial.pdf 

## C# Windows Software

  A base C# windows software is included in this collection. It has serial communication capability. It can log all serial communication transmitted and received data. One advantage about this software is that it is GUI and it is user friendly. Filters can be added to the software to color code the communication data between PC and embedded system. This will be helpful for long running tests or monitoring activities. This software can also be modified to control the embedded system based on interfacing protocol implemented in the Console Thread. 

## Other Debugging Tools

All the tools above are super useful for debugging embedded systems. However, the following tools can be used for signal level debugging and they can be non intrusive. So it is important to keep in mind that in some situations it is better to use non intrusive debugging tools. 

  * Logic Analyzer
  * Oscilloscope
