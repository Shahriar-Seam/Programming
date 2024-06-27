import datetime
import re

def handle_response(_text: str) -> str:  # planning to move this function to BasicFunctions file
    # if any(w in text for w in []):
    text: str = _text.lower()
    if any(w in text for w in ['ku website', 'kuwebsite']):
        return "please visit https://ku.ac.bd "
    if any(w in text for w in ['hi', 'hello', 'hola', 'hlw']):
        # return f"Hi there !!!"
        _current_hour: int = int(datetime.now().hour)
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

    if 'tbtku website' in text:
        return "please visit https://tbtku.github.io "
    if any(w in text for w in ['who are you', 'কে তুমি', 'ke tumi', 'tui keda', 'তুই কেডা']):
        return ("I am a computer program (aka BOT) for the online community tbtKU (Thoughts Behind The KU)\n["
                "https://www.facebook.com/tbtKU]")

    return ("Sorry, I didn't understand that. I am still under development. If you have any suggestions, "
            "please contact/inform @Napatheparacetamol.\nHope, I will continue this conversation like "
            "a chatbot ;)")

# cloned
def handle_response_copy(_text: str) -> str:  # planning to move this function to BasicFunctions file
    # if any(w in text for w in []):
    text: set = {re.sub(r'[^\w\s]', '', _text.lower())}

    if "tbtku website" in text:
        return "please visit https://tbtku.github.io "
    
    if len(set(["ku website", "kuwebsite", "website", "ku"]).intersection(text)) > 0:
        return "please visit https://ku.ac.bd "
    
    if len(set(['hi', 'hello', 'hola', 'hlw']).intersection(text)) > 0:
        # return f"Hi there !!!"
        _current_hour: int = int(datetime.now().hour)
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

    if len(set(['who are you', 'কে তুমি', 'ke tumi', 'tui keda', 'তুই কেডা']).intersection(text)) > 0:
        return ("I am a computer program (aka BOT) for the online community tbtKU (Thoughts Behind The KU)\n["
                "https://www.facebook.com/tbtKU]")

    return ("Sorry, I didn't understand that. I am still under development. If you have any suggestions, "
            "please contact/inform @Napatheparacetamol.\nHope, I will continue this conversation like "
            "a chatbot ;)")


print(handle_response_copy(input()))