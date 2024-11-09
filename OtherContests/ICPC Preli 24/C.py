for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    
    sum = 0
    
    for i in range(n):
        x, y = map(int, input().split())
        
        sum += k // x
        
    print(f"Case {_}: {sum}")