import math

for _ in range(1, int(input()) + 1):
    k = float(input())
    
    b = 1
    
    a = ((b * b * (1 - k * k)) / (k * k - 4)) ** 0.5
    
    print(f"Case {_}: {(a / b):.4}")