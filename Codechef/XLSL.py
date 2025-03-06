for _ in range(1, int(input()) + 1):
    x, y, z, a, b, c = map(int, input().split())
    
    count = 0
    
    count += min(z, c)
    z -= min(z, c)
    y += z
    
    count += min(y, b)
    y -= min(y, b)
    x += y
    
    count += min(x, a)
    
    print(count)