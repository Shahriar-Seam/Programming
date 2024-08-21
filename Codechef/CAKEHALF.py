import math

for _ in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    
    c = 0
    
    while (a != b):
        if a > b:
            c += math.ceil(a / 2)
            a -= math.ceil(a / 2)
        else:
            c += math.ceil(b / 2)
            b -= math.ceil(b / 2)
            
    print(c)