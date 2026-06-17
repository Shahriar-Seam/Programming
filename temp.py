from itertools import permutations
from math import gcd

def f(p, n):
    for i in range(n):
        for j in range(i + 1, n + 1):
            g = gcd(*p[i : j])
            
            if i == 0 and j == n:
                if g == 1:
                    pass
                else:
                    return False
            elif g != 1:
                pass
            else:
                return False
            
    return True

t = int(input())

print(f([2, 6, 10, 5], 4))

for _ in range(t):
    n, m = map(int, input().split())
    c = 0
    s = set()
    
    for p in permutations([i for i in range(1, m + 1)] * n, n):
        if f(p, n):
            s.add(p)
            
    s = sorted(list(s))
    
    print(len(s))
    print(*s, sep="\n")
    print()
    
    