for _ in range(1, int(input()) + 1):
    x, y = map(int, input().split())
    
    initial_dist = x * 10
    
    dist = initial_dist
    count = 11
    
    while (dist)