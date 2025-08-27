def sum(n):
    s = 0
    
    while n > 0:
        s += n % 10
        n //= 10
        
    return s

ss = 0

for i in range(1, 1235):
    ss += sum(i)
    
print(ss)