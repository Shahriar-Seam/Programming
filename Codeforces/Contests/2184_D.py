fact = [1]

for i in range(1, 60):
    fact.append(i * fact[-1])

def bit_len(n):
    l = 0
    
    while n > 0:
        n //= 2
        l += 1
        
    return l

def C(n, k):
    return fact[n] // (fact[k] * fact[n - k])

for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    
    
    n = bit_len(n)
    count = 1
    
    for i in range(2, n):
        for j in range(0, i):
            if j * 2 + i - j <= k:
                count += C(i - 1, j)
                
    if k >= n:
        count += 1
    
    if n == 1:
        print(0)
    else:
        print((1 << (n - 1)) - count)