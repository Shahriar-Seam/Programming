from math import gcd

for _ in range(1, int(input()) + 1):
    x1, y1, x2, y2, k = map(int, input().split())
    
    print("YES" if gcd(abs(x1 - x2), abs(y1 - y2)) + 1 >= k else "NO")