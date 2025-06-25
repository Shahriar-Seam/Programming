from math import sqrt

for _ in range(1, int(input()) + 1):
    l, r = map(int, input().split())
    
    low = int(sqrt(l - 1))
    high = int(sqrt(r))
    
    if (low + 1) ** 2 == l - 1:
        low += 1
        
    if (high + 1) ** 2 == r:
        high += 1
    
    print(high - low)