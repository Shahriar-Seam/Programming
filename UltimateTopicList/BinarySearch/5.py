import io, os, sys

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, t = map(int, input().split())

arr = list(map(int, input().split()))

l, r = 0, max(arr) * t

def possible(m):
    cnt = 0
    
    for i in arr:
        cnt += m // i
    
    return cnt >= t

for _ in range(60):
    m = (l + r) // 2
    
    if possible(m):
        r = m
    else:
        l = m
        
sys.stdout.write(str(r))