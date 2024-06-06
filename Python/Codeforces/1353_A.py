for i in range(1, int(input()) + 1):
    n, m = map(int, input().split())
    
    print(min(2, n - 1) * m)