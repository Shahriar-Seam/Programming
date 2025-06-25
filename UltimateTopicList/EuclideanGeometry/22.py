import math

for _ in range(1, int(input()) + 1):
    x1, y1, x2, y2 = map(int, input().split())
    
    d = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** .5
    
    print(f"{d / 2:.6f}")