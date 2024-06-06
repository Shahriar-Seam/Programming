import math as m

for i in range(1, int(input()) + 1):
    r1, r2, r3 = list(map(float, input().split()))
    
    a = r1 + r2
    b = r2 + r3
    c = r1 + r3
    s = (a + b + c) / 2
    
    area_t = m.sqrt(s * (s - a) * (s - b) * (s - c))

    A = m.acos((b * b + c * c - a * a) / (2 * b * c))
    B = m.acos((a * a + c * c - b * b) / (2 * a * c))
    C = m.acos((a * a + b * b - c * c) / (2 * a * b))
    
    area_3 = 0.5 * r3 * r3 * A
    area_2 = 0.5 * r2 * r2 * C
    area_1 = 0.5 * r1 * r1 * B
    
    area = area_t - (area_1 + area_2 + area_3)
    
    print(f"Case {i}: {area}")