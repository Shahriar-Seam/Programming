import math

for _ in range(1, int(input()) + 1):
    x, y, k = map(int, input().split())
    
    jumps = 0
    
    if y > x - k:
        jumps = 2 * math.ceil(y / k)
    else:
        jumps = 2 * math.ceil(x / k) - 1
    
    print(jumps)