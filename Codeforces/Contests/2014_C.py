for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    sum = 0
    max_id = 0
    
    for i in range(n):
        sum += a[i]
        
        if a[i] > a[max_id]:
            max_id = i
    
    l, r = 0, int(1e12 + 5)
    
    while l < r:
        m = (l + r) // 2
        
        avg = (sum + m) / n
        
        count = 0
        for i in range(n):
            if i != max_id and a[i] < (avg / 2):
                count += 1
            
        if count > n // 2:
            r = m
        else:
            l = m + 1
            
    print(-1 if r == int(1e12 + 5) else r)