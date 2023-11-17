for i in range(1, int(input()) + 1):
    a, b, c = list(map(int, input().split()))
    
    a = a * a
    b = b * b
    c = c * c
    
    if (a + b == c or b + c == a or a + c == b):
        print(f"Case {i}: yes")
    else:
        print(f"Case {i}: no")