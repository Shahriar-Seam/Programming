from math import acos, sqrt

def tri_area(a, b, c):
    s = (a + b + c) / 2
    
    return sqrt(s * (s - a) * (s - b) * (s - c))

def sector_area(r, theta):
    return 0.5 * r * r * theta

for _ in range(1, int(input()) + 1):
    r1, r2, r3 = map(float, input().split())
    
    a = r2 + r3
    b = r1 + r3
    c = r1 + r2
    
    A = acos((b * b + c * c - a * a) / (2 * b * c))
    B = acos((c * c + a * a - b * b) / (2 * c * a))
    C = acos((a * a + b * b - c * c) / (2 * a * b))
    
    area = tri_area(a, b, c) - sector_area(r1, A) - sector_area(r2, B) - sector_area(r3, C)
    
    print(f"Case {_}: {area:.8f}")