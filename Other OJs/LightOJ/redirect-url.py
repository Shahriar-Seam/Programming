import math

for _ in range(1, int(input()) + 1):
    s = input()
    
    if "https" != s[ : 5]:
        s = "https" + s[4 : ]
        
    print(f"Case {_}: {s}")