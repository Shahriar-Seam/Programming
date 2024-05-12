import math
from bisect import bisect_left

max_size = 1000000
marked = [None] * max_size

def sieve():
    marked[0] = marked[1] = 1
    
    for i in range(2, max_size, 2):
        marked[i] = 2
    
    for i in range(3, max_size, 2):
        marked[i] = i

    r = int(math.sqrt(max_size))

    for i in range(3, r, 2):
        if (marked[i] == i):
            for j in range(i * i, max_size, i + i):
                if marked[j] == j:
                    marked[j] = i
            
sieve()

def factor_count(n):
    factors = set()
    
    while (marked[n] != 1):
        factors.add(marked[n])
        
        n //= marked[n]
        
    return len(factors) == 4

for i in range(210, 1000):
    if factor_count(i) and factor_count(i + 1) and factor_count(i + 2) and factor_count(i + 3):
        print(i, i + 1, i + 2, i + 3)