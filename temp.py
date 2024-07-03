from datetime import *
from time import *
import re
import requests
import pytz


def handle_response(_text: str) -> str:  # thanks to IA Seam 230201 for enhancing this function
    # if any(w in text for w in []):
    _text: str = re.sub(r'[^\w\s]', ' ', _text.lower())
    text: set = set(re.sub(r'[^\w\s]', '', _text.lower()).split())
    
    # return text # debug

    # if len(set([""]).intersection(text)) > 0:
    #     return "please visit https://ku.ac.bd "

    if "tbtku website" in _text:
        return "please visit https://tbtku.github.io "

    if "ku website" in _text or len(set(["kuwebsite", "ku"]).intersection(text)) > 0:
        return "please visit https://ku.ac.bd "

    if len(set(["magazine"]).intersection(text)) > 0:
        # ku_webpage_content: str = requests.get("https://ku.ac.bd/").text
        # print(ku_webpage_content)
        # magazine_url = re.search(r'<a href="(.+)">KU Barta</a>', ku_webpage_content)
        magazine_url = ("https://drive.google.com/file/d/1ltGVmZHGjW9B0eUjrd5eEl56b9guoXcK/view [99th edition, "
                        "July to Sept 2023]")
        # <a href=".">KU Barta</a>
        return f"for KU Magazine, please visit {magazine_url}"

    if "how are you" in _text:
        return "I am fine ;)"

    if len(set(['hi', 'hello', 'hola', 'hlw']).intersection(text)) > 0:
        # return f"Hi there !!!"
        Asia_Dhaka_tz = pytz.timezone('Asia/Dhaka')
        _current_hour_dhaka = datetime.now(Asia_Dhaka_tz).strftime("%H")
        _current_hour: int = int(_current_hour_dhaka)
        _current_greeting: str = ""
        if 6 <= _current_hour < 12:
            _current_greeting = "Morning"
        elif 12 <= _current_hour < 16:
            _current_greeting = "Noon"
        elif 16 <= _current_hour < 19:
            _current_greeting = "Afternoon"
        else:
            _current_greeting = "Evening"
        return f"Hi there! Good {_current_greeting}!"
        # END OF Hi there!

    if len(set(["ambulance"]).intersection(text)) > 0:
        return ("Khulna University Ambulance Number [Update of June 2024]\n\nAmbulance KU - Abul  "
                "+8801976207850\nAmbulance KU - Humayun  +8801923456228\nAmbulance KU - Mithun Ghosh  "
                "+8801511927362\nAmbulance KU - Nuru  +8801715549122\nAmbulance KU - Rafik  +8801726803359\n\nWhile "
                "starting a conversation, please confirm it first whether is it right person or not. If you notice "
                "anyissues, please inform us https://forms.gle/KfTayNZj1kZktBF79 \n\n**Suggestion: Save all important "
                "contact to your phone just in a minute by importing this csv/vcf file, details:**")

    if len(set(["police"]).intersection(text)) > 0:
        return ("Khulna Police Station[Update of June 2024]\n\nPolice Sonadanga Thana OC  +8801320058409\nKhulna "
                "Metropolitan Police  +8801320-060998 ; +8801320-060999\nPolice Harintana Thana OC  "
                "+8801320058463\n\n**Suggestion: Save all important"
                "contact to your phone just in a minute by importing this csv/vcf file, details:**")

    if any(s in _text for s in ['who are you', 'কে তুমি', 'ke tumi', 'tui keda', 'তুই কেডা']):
        return ("I am a computer program (aka BOT) for the online community tbtKU (Thoughts Behind The KU)\n"
                "I am here to assist you")

    return ("Sorry, I didn't understand that. I am still under development.\nIf you have any suggestions, "
            "please fill this form https://forms.gle/KfTayNZj1kZktBF79 to share your feedback.\nHope, I will continue "
            "this conversation like a chatbot in future ;)")

# ================================
# =========== Archive ============
# ================================


print(handle_response(input()))