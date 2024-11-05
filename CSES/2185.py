n, k = map(int, input().split())
a = list(map(int, input().split()))

sum = 0

for mask in range(1, (1 << k)):
    product = 1
    pop = 0
    
    for i in range(k):
        if mask & (1 << i):
            pop += 1
            
            product *= a[i]
            
        if product > n:
            break
    
    if pop & 1:
        sum += (n // product)
    else:
        sum -= (n // product)

print(sum)