from sys import stdin
from math import sin, pi

for line in stdin:
    r, n = map(float, line.split())
    
    area = r * r * sin(2 * pi / n) * n / 2
    
    print(f"{area:.3f}")