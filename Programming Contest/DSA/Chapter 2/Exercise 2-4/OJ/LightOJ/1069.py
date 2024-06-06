for i in range(1, int(input()) + 1):
    a, b = list(map(int, input().split()))
    
    result = 19 + abs(a - b) * 4 + a * 4
    
    print(f"Case {i}: {result}")