def sqrt(n):
    l = -1
    r = n
    
    while r - l > 1:
        m = (l + r) // 2
        
        if m * m >= n:
            r = m
        elif m * m < n:
            l = m
            
    return r - 1

for _ in range(1, int(input()) + 1):
    n = int(input())
    
    print(sqrt(n))