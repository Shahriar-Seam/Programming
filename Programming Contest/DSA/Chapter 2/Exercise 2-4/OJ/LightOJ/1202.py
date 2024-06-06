for i in range (1, int(input()) + 1):
    r1, c1, r2, c2 = list(map(int, input().split()))
    
    c = abs(c1 - c2)
    r = abs(r1 - r2)
    
    if (c == r):
        print(f"Case {i}: 1")
    elif (c % 2 == r % 2):
        print(f"Case {i}: 2")
    else:
        print(f"Case {i}: impossible")