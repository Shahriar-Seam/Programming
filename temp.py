import pyttsx3

mohi = pyttsx3.init()

voices = mohi.getProperty('voices')
mohi.setProperty('voice', voices[1].id)

mohi.say("Kaziii")
mohi.runAndWait()