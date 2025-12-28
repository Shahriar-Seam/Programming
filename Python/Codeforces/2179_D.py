def suffix(n):
    c = 0
    
    for i in range(20):
        if n & (1 << i):
            c += 1
        else:
            break
    
    return c

for _ in range(int(input())):
    n = int(input())
    
    l = [[] for i in range(n + 1)]
    
    for i in range(1 << n):
        l[suffix(i)].append(i)
        
    for i in range(n, -1, -1):
        print(*l[i], end=' ')
    
    print()