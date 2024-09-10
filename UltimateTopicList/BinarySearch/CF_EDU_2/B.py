import math

def count(arr, m):
    cnt = 0
    
    for i in arr:
        cnt += math.floor(i / m)
    
    return cnt

n, k = map(int, input().split())

arr = []

for _ in range(n):
    arr.append(float(input()))

l, r = 0.0, max(arr)
length = 0.0

for _ in range(500):
    m = (l + r) / 2
    
    cnt = count(arr, m)
    
    if cnt >= k:
        if cnt == k:
            length = max(length, m)
            
        l = m
    else:
        r = m
        
print(length)