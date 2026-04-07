from math import gcd as g

for _ in range(1, int(input()) + 1):
    n, m, a, b = map(int, input().split())
    
    print("YES" if g(n, a) == 1 and g(m, b) == 1 and g(n, m) <= 2 else "NO")
    