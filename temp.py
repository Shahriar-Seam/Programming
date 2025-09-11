def s(n):
    ss = 0
    
    while n:
        ss += n % 10
        n //= 10
        
    return ss

n = int(input())

N = 0

for i in range(1, n + 1):
    N = N + int("9" * i)
    
    print(s(N))