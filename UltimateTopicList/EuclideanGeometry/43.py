for _ in range(1, int(input()) + 1):
    h, w = map(int, input().split())
    
    count = 0
    
    if h > w:
        h, w = w, h
    
    for i in range(1, 1000):
        if (w - 4 * i + 1) <= 0 or (h - 2 * i + 1) <= 0:
            break
        
        count += max(0, w - 4 * i + 1) * max(0, h - 2 * i + 1)
        
        print(i, w - 4 * i + 1, h - 2 * i + 1)
        
    print(count)