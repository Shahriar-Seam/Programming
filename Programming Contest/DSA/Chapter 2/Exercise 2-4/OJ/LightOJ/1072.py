import math as m

for i in range (1, int(input()) + 1):
    R, n = list(map(float, input().split()))
    N = int(n)
    
    r = m.sin(m.pi / N) * R / (1 + m.sin(m.pi / N))
    
    print(f"Case {i}: {r}")