from math import sqrt

def valid(a, b, c):
    return a + b > c

def area(a, b, c):
    s = (a + b + c) / 2
    
    return sqrt(s * (s - a) * (s - b) * (s - c))

for _ in range(1, int(input()) + 1):
    t = list(map(float, input().split()))
    
    n = int(t.pop(0))
    
    t.sort()
    
    max_area = 0.0
    
    for i in range(2, n):
        if valid(t[i - 2], t[i - 1], t[i]):
            max_area = max(max_area, area(t[i - 2], t[i - 1], t[i]))
            
    print(f"{max_area:.2f}")