for _ in range(1, int(input()) + 1):
    a, b = map(str, input().split())
    
    a = ord(a) - 33
    b = ord(b) - 33
    
    print(f"Case {_}:")
    for i in range(1, 95):
        if (a % i) == (b % i):
            print(i, (94 + i - 1) // i)
            
    print()