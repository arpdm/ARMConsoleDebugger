## Python UART/Serial Source Code
## This code can be used for interfacing with embedded system using UART/USB cable
## the serial comm configuration parameters need to match the parameters set on Embedded System
## This code is bare minimum. Other features can be developed on top of it

import serial
import time
import io

## Configuration Parameters

COM_PORT  = 'COM3'
BAUD_RATE = 9600
TIME_OUT  = 10

## Create Instance Of Serial Object

serialObj = serial.Serial(COM_PORT,BAUD_RATE,timeout=TIME_OUT)

while 1:

	## Try reading data

	try:
	
		data = serialObj.readline()
		print (data)

	## Handle execptions

	except serialObj.SerialTimeoutException:

		print("Data could not be read")
	


def closePort():
	serialObj.close()
