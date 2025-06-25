from math import acos

for _ in range(1, int(input()) + 1):
    l = int(input())
    
    rect = l * l * 6 / 10
    red = acos(-1) * (l / 5) ** 2
    green = rect - red
    
    print(f"{red:.2f} {green:.2f}")