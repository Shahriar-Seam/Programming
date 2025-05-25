from math import acos, sin

eps = 1e-10

def valid(x, y, c, d):
    theta_y = acos(d / y)
    theta_x = acos(d / x)
    
    h_y = y * sin(theta_y)
    h_x = x * sin(theta_x)
    
    d_y = c * d / h_y
    d_x = c * d / h_x
    
    return d_x + d_y >= d

for _ in range(1, int(input()) + 1):
    x, y, c = map(float, input().split())
    
    l, r, m = 0, min(x, y), 0
    
    while r - l > eps:
        m = (l + r) / 2
        
        if valid(x, y, c, m):
            d = m
            
            r = m
        else:
            l = m
    
    print(f"Case {_}: {d:.10f}")