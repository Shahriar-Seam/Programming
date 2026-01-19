n, k, x = map(int, input().split())
a = list(map(int, input().split()))

a.sort(reverse=True)

a = a[n - k : ]

count = n - k

for i in range(len(a)):
    if x <= 0:
        break
    
    count += 1
    x -= a[i]
    
print(count if x <= 0 else -1)