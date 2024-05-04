import math

s = 0

for i in range(3, 34):
    phi = (1 + math.sqrt(5)) / 2
    phi_c = (1 - math.sqrt(5)) / 2
    fib = int((1 / math.sqrt(5)) * (phi ** i - phi_c ** i))
    
    if (fib % 2 == 0):
        s += fib
        
    print(fib)
print(s)