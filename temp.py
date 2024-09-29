import pyautogui
import time

time.sleep(3)

for _ in range(50):
    pyautogui.typewrite("bleh")
    pyautogui.press('Enter')
    
    time.sleep(0.001)