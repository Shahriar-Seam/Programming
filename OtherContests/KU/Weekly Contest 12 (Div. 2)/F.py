import math

inf = 10000000000

for _ in range(1, int(input()) + 1):
    xl, xh, yl, yh, zl, zh = 0, inf, 0, inf, 0, inf
    
    for i in range(int(input())):
        a = list(map(int, input().split()))
        
        xl = max(xl, a[0])
        yl = max(yl, a[1])
        zl = max(zl, a[2])
        
        xh = min(xh, a[3])
        yh = min(yh, a[4])
        zh = min(zh, a[5])
    
    print(f"Case {_}:", end=" ")
    print(max(0, (xh - xl) * (yh - yl) * (zh - zl)))