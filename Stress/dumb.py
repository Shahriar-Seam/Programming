import math

for _ in range(1, int(input()) + 1):
    x, y = map(int, input().split())
    
    mx = 0
    s = x + y
    
    for x in range(x, -1, -1):
        mx = max(mx, x ^ y)
        
        if mx == s:
            break
        
        y += 1
        
    if mx != s:
        print(mx)