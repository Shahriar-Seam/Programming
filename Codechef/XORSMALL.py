for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    temp = a[0]
    
    for i in a:
        temp &= i
    
    count = 0
    
    i = 1
    while i < (1 << 32):
        if temp & i:
            count += i
        
        i *= 2
    
    print(count)