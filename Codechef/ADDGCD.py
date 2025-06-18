import math

for _ in range(1, int(input()) + 1):
    x, y = map(int, input().split())
    g = math.gcd(x, y)
    
    if (g > 1):
        print(0)
    elif math.gcd(x + 1, y) > 1 or math.gcd(x, y + 1) > 1:
        print(1)
    else:
        print(2)