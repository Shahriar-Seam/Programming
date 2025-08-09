def lower_bound(a, x):
    low, high = 0, len(a)
    
    while low < high:
        mid = (low + high) // 2
    
        if a[mid] < x:
            low = mid + 1
        else:
            high = mid
    
    return low

n, q = map(int, input().split())

a = list(map(int, input().split()))

a.sort()

pref = [0] * (n + 1)

for i in range(n):
    pref[i + 1] = pref[i] + a[i]

while q > 0:
    q -= 1
    
    b = int(input())
    
    if b == 1:
        print(1)
    else:
        index = lower_bound(a, b)
        result = pref[index] + (n - index) * (b - 1) + 1
        
        print(-1 if result > pref[-1] else result)