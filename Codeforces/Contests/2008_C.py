import math

for _ in range(1, int(input()) + 1):
    l, r = map(int, input().split())
    
    diff = r - l + 1
    
    n = int((-1 + math.sqrt(1 + 8 * diff)) // 2)
    
    if diff > 1:
        n += 1
    
    print(n)