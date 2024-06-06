for i in range(1, int(input()) + 1):
    n, k = list(map(int, input().split()))
    
    print(n - (n // (k + 1)) * k)