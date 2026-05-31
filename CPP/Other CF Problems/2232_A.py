for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    m = list(sorted(a))
    m1 = m[(len(m) - 1) // 2]
    m2 = m[len(m) // 2]
    
    l1 = len([i for i in a if i < m1])
    r1 = len([i for i in a if i > m1])
    
    l2 = len([i for i in a if i < m2])
    r2 = len([i for i in a if i > m2])
    
    print(min(max(l1, r1), max(l2, r2)))