from math import gcd

for _ in range(1, int(input()) + 1):
    a, b, c = map(int, input().split())
    
    num = (a + b + c) * (a + b - c) * (b + c - a) * (a + c - b)
    
    denom = 4 * (a + b + c) ** 2
    
    g = gcd(num, denom)
    
    num //= g
    denom //= g
    
    print(f"{num}/{denom}")