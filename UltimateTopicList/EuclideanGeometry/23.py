from math import sin, pi

for _ in range(1, int(input()) + 1):
    R, n = map(float, input().split())
    
    r = R * sin(pi / n) / (1 + sin(pi / n))
    
    print(f"Case {_}: {r:.8f}")