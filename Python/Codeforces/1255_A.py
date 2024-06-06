for i in range(1, int(input()) + 1):
    a, b = list(map(int, input().split()))
    n = abs(a - b)
    
    cnt = 0
    
    cnt += n // 5
    
    n = n % 5
    
    cnt += n // 2
    
    n = n % 2
    
    cnt += n
    
    print(cnt)