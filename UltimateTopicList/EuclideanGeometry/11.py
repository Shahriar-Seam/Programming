from math import sqrt

for _ in range(1, int(input()) + 1):
    ab, ac, bc, r = map(float, input().split())
    
    r = 1 / r
    
    ad = sqrt(ab * ab / (1 + r))
    
    print(f"Case {_}: {ad}")