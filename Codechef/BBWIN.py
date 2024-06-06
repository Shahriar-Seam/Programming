import math

for i in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    
    if (a >= b + 10):
        print("0")
    else:
        print(((10 - (a - b) + 2) // 3))