from math import gcd

G = 0
N = int(input())
l = [[] for i in range(N + 1)]

for i in range(1, N):
    for j in range(i + 1, N + 1):
        g = gcd(i, j)
        
        l[g].append((i, j))
        
        G += g
        
print(G)

print(*l, sep="\n\n")