from sys import stdin
from math import tan, pi

for line in stdin:
    l, w, h, theta = map(int, line.split())
    
    b = l * tan(theta * pi / 180)
    
    area = 0.0
    
    if b > h:
        area = 0.5 * h * h / tan(theta * pi / 180)
    else:
        area = h * l - 0.5 * l * b
        
    print(f"{w * area:.3f} mL")