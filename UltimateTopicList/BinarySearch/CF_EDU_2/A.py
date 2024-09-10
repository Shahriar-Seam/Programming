w, h, n = map(int, input().split())

def possible(x):
    return (x // w) * (x // h) >= n

l, r = 0, 1 << 62
x = 0

while l <= r:
    m = (l + r) // 2
    
    if possible(m):
        x = m
        r = m - 1
    else:
        l = m + 1
    
print(x)