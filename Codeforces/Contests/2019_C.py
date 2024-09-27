import math

def possible(s, m, k):
    return (math.ceil(s / m) * m) <= (s + k)
                
        
for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    s = sum(a)
    
    l, r = 1, s + k
    
    while l <= r:
        m = (l + r) // 2
        
        if possible(s, m, k):
            l = m + 1
        else:
            r = m - 1
            
    print(math.ceil(s / (l - 1)))