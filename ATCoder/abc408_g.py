import math

def valid(l, r):
    if (math.floor(r) == r and math.floor(l) == l) and r - l > 1:
        return True
    else:
        return math.floor(l) < math.floor(r)

for _ in range(1, int(input()) + 1):
    a, b, c, d = map(int, input().split())
    
    for q in range(1, 1001):
        l = (a / b) * q + 1e-9
        r = (c / d) * q - 1e-9
        
        if valid(l, r):
            break
        
    print(q)