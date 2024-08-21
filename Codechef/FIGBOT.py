import math

for _ in range(1, int(input()) + 1):
    n, x, y = map(int, input().split())
    s = input()
    
    points = []
    a_x, a_y = 0, 0
    f = 0
    
    for c in s:
        if c == 'L':
            a_x -= 1
        elif c == 'R':
            a_x += 1
        elif c == 'U':
            a_y += 1
        else:
            a_y -= 1
        
        points.append([a_x, a_y])
    
    for i in range(n):
        p = points[i]
        
        a_x, a_y = p[0], p[1]
        
        if abs(x - a_x) + abs(y - a_y) == i + 1:
            f = 1
            break
        
    print("Yes" if f == 1 else "No")