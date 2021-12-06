import serial
import time

opencr = serial.Serial(port='/dev/ttyACM0',baudrate= 115200, timeout= 1)

while True:
    number = str.encode(input('Enter a number : '))
    opencr.write(number)
    time.sleep(0.1)
    value = opencr.readline().decode()
    print('Result : ',value)