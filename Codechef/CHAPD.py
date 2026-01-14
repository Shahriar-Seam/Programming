from math import gcd

for _ in range(int(input())):
    a, b = map(int, input().split())
    
    while gcd(a, b) > 1 and b > 1:
        b //= gcd(a, b)
    
    print("Yes" if b == 1 else "No")