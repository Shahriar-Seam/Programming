import math as m

for i in range(1, int(input()) + 1):
    ox, oy, ax, ay, bx, by = list(map(int, input().split()))
    
    OA = OB = m.sqrt((ox - ax) ** 2 + (oy - ay) ** 2)
    AB = m.sqrt((ax - bx) ** 2 + (ay - by) ** 2)
    
    Theta = m.acos((OA * OA + OB * OB - AB * AB) / (2 * OA * OB))
    
    arc = OA * Theta
    
    print(f"Case {i}: {arc}")