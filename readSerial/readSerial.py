# this code can be use to read data measure from 
# the Arduino through a USB cable with python

import serial
import matplotlib.pyplot as plt

# make sure to set the same baudrate on the arduino
# and modify the device according to your OS
ser = serial.Serial('/dev/tty.usbmodem1421',baudrate=1200)

count = 0
max_count = 500
values = []
while count < max_count:
    
    val = ser.readline().strip().split()
    print val
    count = count + 1

plt.plot(range(0, max_count, 1), values)
plt.xlabel('Count')
plt.ylabel('Value')
plt.show()
