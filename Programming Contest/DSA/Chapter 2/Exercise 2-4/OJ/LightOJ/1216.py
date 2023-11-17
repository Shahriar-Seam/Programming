import math as m

for i in range(1, int(input()) + 1):
    r1, r2, h, p = list(map(int, input().split()))
    
    r3 = p * (r1 - r2) / h + r2
    
    juice = (m.pi / 3) * p * (r3 ** 2 + r2 ** 2 + (r3 * r2))
    
    print(f"Case {i}: {juice}")