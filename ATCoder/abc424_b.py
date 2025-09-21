n, m, k = map(int, input().split())

l = []
c = [0 for i in range(n + 1)]

for _ in range(k):
    a, b = map(int, input().split())
    
    c[a] += 1
    
    if c[a] == m:
        l.append(a)
        
print(*l)