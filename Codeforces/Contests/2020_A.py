import math

for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    
    count = 0
    
    if (k == 1):
        print(n)
        
        continue
    
    while n > 0:
        temp = math.log(n) // math.log(k)
        
        if k ** (temp + 1) <= n:
            temp += 1
            
        n -= pow(k, temp)
        count += 1
        
    print(count)