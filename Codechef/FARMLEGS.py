import math

for i in range(1, int(input()) + 1):
    n = int(input())
    
    if (n % 4 > 0):
        print((n // 4) + 1)
    else:
        print(n // 4)