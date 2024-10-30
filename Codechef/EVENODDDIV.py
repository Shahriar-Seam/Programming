import math

def f(n):
    odd = 0
    even = 0
    for i in range(1, n + 1):
        if n % i == 0:
            if i & 1:
                odd += 1
            else:
                even += 1
                
    return 1 if even > odd else 0 if even == odd else -1

for _ in range(1, int(input()) + 1):
    n = int(input())
    
    print(f(n))