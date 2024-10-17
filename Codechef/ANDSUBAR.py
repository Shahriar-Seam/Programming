import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    
    if n > 1 and n & (n - 1) == 0:
        n -= 1
    
    p = 2 ** int(math.log2(n))
    
    print(max(n - p + 1, 2 ** (int(math.log2(n) - 1))))