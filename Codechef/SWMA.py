import math

for i in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    
    if (a <= b and (int(str(a)[::-1]) <= b) and (int(str(a)[::-1]) <= int(str(b)[::-1])) and (a <= int(str(b)[::-1]))):
        print("No")
    else:
        print("Yes")