for _ in range(1, int(input()) + 1):
    n = int(input())
    count = 0
    
    for i in range(n // 2 + 1):
        count += i * (n - i) + 1
        
    print(count)
    