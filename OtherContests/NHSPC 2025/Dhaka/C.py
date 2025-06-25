a1, b1, c1 = map(int, input().split())
a2, b2, c2 = map(int, input().split())

if a1 * b2 == a2 * b1:
    if b1 * c2 == b2 * c1:
        print("Infinite Intersections")
    else:
        print("Never Intersect")
else:
    x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1)
    y = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2)
    
    if x == -0:
        x = 0
    if y == -0:
        y = 0
    
    print(f"{x:.6f} {y:.6f}")