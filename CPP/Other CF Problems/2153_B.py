for _ in range(1, int(input()) + 1):
    x, y, z = map(int, input().split())
    
    a = x
    b = x
    c = y
    b |= y
    a |= z
    c |= z
    
    if (a & b) == x and (b & c) == y and (a & c) == z:
        print("YES")
    else:
        print("NO")