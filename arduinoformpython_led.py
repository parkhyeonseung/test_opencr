import serial
import cv2

opencr = serial.Serial(port='/dev/ttyACM0',baudrate= 115200, timeout= 1)
number = 1
cv2.namedWindow('a')
while True:
    key = cv2.waitKey(1)
    if key == ord("1"):
        number = str.encode('1')
    if key == ord("2"):
        number = str.encode('2')
    if key == ord("3"):
        number = str.encode('3')
    if key == ord("4"):
        number = str.encode('4')
    if key == ord("5"):
        number = str.encode('5')
    if key == ord('q'):
        break
    opencr.write(number)
