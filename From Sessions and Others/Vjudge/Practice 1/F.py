for i in range(1, int(input()) + 1):
    first, second = map(int, input().split())
    n, m = map(int, input().split())
    
    coins = min(first * (m * (n // (m + 1))) + min(first, second) * (n % (m + 1)), min(first, second) * n)
    
    print(coins)