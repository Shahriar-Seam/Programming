for i in range(1, int(input()) + 1):
    ax, ay, bx, by, cx, cy = list(map(int, input().split()))
    
    dx = ax + cx - bx
    dy = ay + cy - by
    
    area = abs(int(1 / 2 * ((ax * by + bx * cy + cx * dy + dx * ay) - (ay * bx + by * cx + cy * dx + dy * ax))))
    
    print(f"Case {i}: {dx} {dy} {area}")