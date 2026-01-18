for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(set(list(map(int, input().split()))))
    
    a.sort()
    
    cnt, count = 0, 0
    
    n = len(a)
    
    for i in range(1, n):
        cnt = 0
        
        while i < n and a[i] - a[i - 1] == 1:
            cnt += 1
            i += 1
        
        count = max(count, cnt)
        
    print(count + 1)