import math

for i in range(1, int(input()) + 1):
    s = input()
    
    if (min(s.count('0'), s.count('1')) % 2 == 0):
        print("NET")
    else:
        print("DA")