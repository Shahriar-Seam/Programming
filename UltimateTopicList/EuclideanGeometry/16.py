from sys import stdin
from math import sqrt

for line in stdin:
    a, b, c = map(float, line.split())
    
    s = (a + b + c) / 2
    
    d = s * (s - a) * (s - b) * (s - c)
    
    if d <= 0:
        print("-1.000")
    else:
        print(f"{(4 / 3) * sqrt(d):.3f}")
