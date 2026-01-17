import io, os, sys
from functools import lru_cache

sys.set_int_max_str_digits(100000)

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

@lru_cache
def fib(n):
    if n == 0:
        return 0, 1
    
    a, b = 0, 1
    
    for i in range(n.bit_length() - 1, -1, -1):
        c = a * (2 * b - a)
        d = a * a + b * b
        
        if (n >> i) & 1:
            a, b = d, c + d

        else:
            a, b = c, d

    return a, b
    
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())
    xx = list(map(int, input().split()))
    l = []
    
    for i in range(n - 1):
        l.append([max(a[i], a[i + 1]), min(a[i], a[i + 1])])
        
    l.sort(reverse=True)
    
    for i in range(q):
        score = 0
        x = xx[i]
        
        for j in range(min(len(l), 20)):
            a = l[j][0]
            b = l[j][1]
            f = fib(x + 2)
            
            score = max(score, (f[1] - 2) * a + (f[0] - 1) * b)
            
        sys.stdout.write(str(score % 998244353) + " ")
        
    sys.stdout.write("\n")