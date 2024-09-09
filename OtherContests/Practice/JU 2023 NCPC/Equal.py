import math

for _ in range(1, int(input()) + 1):
    a, b, c, d = map(int, input().split())
    
    g1 = math.gcd(a, b)
    
    a //= g1
    b //= g1

    g2 = math.gcd(c, d)
    
    c //= g2
    d //= g2    
    
    print("Equal" if (a == c) and (b == d) else "Not Equal")
    