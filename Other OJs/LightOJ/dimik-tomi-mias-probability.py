from math import factorial as f
from collections import Counter

for _ in range(1, int(input()) + 1):
    s = list(input().split())
    c = Counter(s)
    
    p = f(len(s))
    
    for i in c:
        p //= f(c[i])
        
    print(f"1/{p}")