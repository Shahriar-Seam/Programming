for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    max_a = 0
    
    for i in range(n):
        for j in range(i, n):
            max_a = max(max_a, (sum(a[i : j + 1]) // (j - i + 1)))
            
    print(max_a)