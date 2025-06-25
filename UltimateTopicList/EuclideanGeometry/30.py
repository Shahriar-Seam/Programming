from math import sqrt, acos

def dist(x, y, x0, y0):
    return sqrt((x - x0) ** 2 + (y - y0) ** 2)

for _ in range(1, int(input()) + 1):
    Ox, Oy, Ax, Ay, Bx, By = map(float, input().split())
    
    a = dist(Ox, Oy, Ax, Ay)
    b = dist(Ox, Oy, Bx, By)
    ab = dist(Ax, Ay, Bx, By)
    theta = acos((a * a + b * b - ab * ab) / (2 * a * b))
    
    print(f"Case {_}: {a * theta:.6f}")