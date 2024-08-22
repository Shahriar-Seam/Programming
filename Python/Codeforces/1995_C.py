for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    f = 1
    count = 0
    
    for i in range(1, n):
        if a[i] == 1 and a[i - 1] > 1:
            f = 0
            break
        while a[i] < a[i - 1]:
            a[i] *= a[i]
            count += 1
    
    print(-1 if f == 0 else count)
    