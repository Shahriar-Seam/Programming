import math

for _ in range(1, int(input()) + 1):
    x, y, z = map(int, input().split())
    
    if z == 0 and x > 0:
        print("NO")
    elif x == 0:
        print("YES")
    elif z >= x:
        print("YES")
    elif z == x - 1 and y == 0:
        print("YES")
    else:
        print("NO")