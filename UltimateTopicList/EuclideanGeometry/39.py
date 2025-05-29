import math

for _ in range(1, int(input()) + 1):
    a, b, c = map(float, input().split())
    
    if b * b - a * c <= 0:
        print(f"Case {_}: {-1}")
    else:
        d = (a * c * (a + 2 * b + c)) / (b * b - a * c)
        
        print(f"Case {_}: {d:.8f}")