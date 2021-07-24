import serial
import pyautogui
import pydirectinput
import time
Arduino_Serial = serial.Serial('COM5', 115200)
Arduino_Serial.timeout = 0.01
time.sleep(1) 

while True:
    #Words = Arduino_Serial.read(Arduino_Serial.inWaiting() + 32)
    Words = Arduino_Serial.read(Arduino_Serial.inWaiting())
    #print(Words)

        
    if(Words == b'l'):
        pydirectinput.keyDown('h')
        pydirectinput.keyUp('h')
            
    if(Words == b'r'):
        pydirectinput.keyDown('a')
        pydirectinput.keyUp('a')
        
    if(Words == b'd'):
        pydirectinput.keyDown('b')
        pydirectinput.keyUp('b')
            
    if(Words == b'u'):
        pydirectinput.keyDown('c')
        pydirectinput.keyUp('c')

    
        
        
    # good enough for action buttons but the Dpad is just not good with it
    
    

    
        
        
        

    
           
    
