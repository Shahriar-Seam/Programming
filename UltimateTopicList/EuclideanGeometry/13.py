from math import sqrt

for _ in range(1, int(input()) + 1):
    a, b, c = map(int, input().split())
    
    d = (a * b * c) / (a * b + b * c + c * a + 2 * sqrt(a * b * c * (a + b + c)))
    
    print(d)