import serial
import time

ser = serial.Serial('COM3',9600,timeout=10)

while 1:
	try:
		print ser.readline()
	except ser.SerialTimeoutException:
		print("Data could not be read")
	