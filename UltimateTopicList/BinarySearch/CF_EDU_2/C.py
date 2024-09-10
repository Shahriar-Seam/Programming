    

n, x, y = map(int, input().split())

n += 1

l, r = 0, 2 << 60

def possible(m):
    return (m // x) + (m // y) >= n

for _ in range(100) or l <= r:
    m = (l + r) // 2
    
    if possible(m):
        r = m
    else:
        l = m
    
print(r)