import math

for i in range(1, int(input()) + 1):
    x, y = map(int, input().split())
    
    s = bin(x ^ y)[::-1]
    
    count = 0
    for c in s:
        if (c == '0'):
            count += 1
        else:
            break
    
    print(2 ** count)