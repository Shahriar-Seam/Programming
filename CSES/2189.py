for _ in range(1, int(input()) + 1):
    x1, y1, x2, y2, x, y = map(int, input().split())
    
    d = (x - x1) * (y1 - y2) - (y - y1) * (x1 - x2)
    
    print("LEFT" if d > 0 else "TOUCH" if d == 0 else "RIGHT")