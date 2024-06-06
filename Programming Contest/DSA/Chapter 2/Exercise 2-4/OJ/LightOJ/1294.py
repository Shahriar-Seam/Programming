for i in range (1, int(input()) + 1):
    n, m = list(map(int, input().split()))
    
    a = int(n / (2 * m))
    
    print(f"Case {i}: {m * m * a}")