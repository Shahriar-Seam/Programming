for _ in range(int(input())):
    n = int(input())
    
    p = [None] * n
    
    for i in range((n + 1) // 2):
        p[i] = n - 2 * i
        
    j = 0
    for i in range(n - 1, (n - 1) // 2, -1):
        p[i] = n - (2 * j + 1)
        j += 1
        
    print(*p)