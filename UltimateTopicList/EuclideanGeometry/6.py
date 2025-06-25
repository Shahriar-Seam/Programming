from sys import stdin
from math import pi, cos, sqrt

for line in stdin:
    s, a, d = line.split()
    
    s = float(s) + 6440
    a = int(a)
    
    if d == 'min':
        a /= 60

    a = a % 360
    a = min(a, 360 - a)

    theta = pi * a / 180
    
    arc = s * theta + 1e-9
    chord = sqrt(2 * s * s - 2 * s * s * cos(theta)) + 1e-9
    
    print(f"{arc:.6f} {chord:.6f}")