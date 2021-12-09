import serial
import cv2

opencr = serial.Serial(port='/dev/ttyACM0',baudrate= 115200, timeout= 1)
number = 1
cv2.namedWindow('a')
while True:
    key = cv2.waitKey(1)
    if key == ord("w"):
        number = str.encode("w")
    if key == ord("s"):
        number = str.encode('s')
    if key == ord("d"):
        number = str.encode('d')
    if key == ord("a"):
        number = str.encode('a')
    if key == ord(" "):
        print(' ')
        number = str.encode(' ')
    if key == ord('q'):
        break
    opencr.write(number)
