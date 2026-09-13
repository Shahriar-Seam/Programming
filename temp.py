from functools import lru_cache

@lru_cache
def f(n):
    return n * (1 << (n - 1))

for n in range(1, 15):
    cnt = 0
    
    for i in range(1 << n):
        cnt += bin(i).count('1')
        
    print((1 << n), cnt, f(n))