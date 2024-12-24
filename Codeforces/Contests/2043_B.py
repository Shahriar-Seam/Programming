for _ in range(int(input())):
    n, d = map(int, input().split())
    
    print(1, end=' ')
    
    if n >= 3 or d == 9 or d == 3 or d == 6:
        print(3, end=' ')
    if d == 5:
        print(5, end=' ')
    if d == 7 or n >= 3:
        print(7, end=' ')
    if d == 9 or ((d == 3 or d == 6) and n >= 3) or n >= 6:
        print(9, end=' ')
    
    print()