import math

for i in range(1, int(input()) + 1):
    n, b, k = list(map(int, input().split()))
    
    g = n - b
    
    g = g % k
    b = b % k
    
    print(max(g, b) - min(g, b))