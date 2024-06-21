def encode(strs: list[str]) -> str:
    string = ""

    for s in strs:
        string = string + "#" + s

    return string

def decode(s: str) -> list[str]:
    strs = s.split('#')
    strs.pop(0)

    return strs

strs = ["neet", "code", "love", "you"]

print(encode(strs))
print(decode(encode(strs)))