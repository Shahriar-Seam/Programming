import math

for _ in range(1, int(input()) + 1):
    s, k, m = map(int, input().split())
    
    flips = m // k
    
    if k > m:
        print(max(0, s - k))
    else:
        if flips & 1:
            s = min(s, k)
        
        print(max(0, s - m % k))