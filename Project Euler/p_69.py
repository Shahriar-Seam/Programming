def phi(n):
    
    result = n
    
    p = 2
    
    while (p * p <= n):
        if (n % p == 0):
            
            while (n % p == 0):
                n = n // p
            
            result -= result // p
            
        p += 1
        
    if n > 1:
        result -= result // n
        
    return result - 1

m = 0
num = 0

for n in range(3, 10):
    p = phi(n)
    
    # print(n, p, n // p)
    
    if (n // p) > m:
        m = n // p
        num = n
        
print(num)