import pyttsx3 as kazi
import random as r
import time

def run():
    exit()
    
def kobul():
    kazi.speak("kobul")
    
for cnt in range (0, 3):
    kobul()
    
rifat = True

r.seed()

acr = r.randint(0, 1)

rifat = True if acr else False

time.sleep(1)

if rifat:
    kazi.speak("Yes")
else:
    kazi.speak("No")

run()