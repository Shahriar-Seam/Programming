for _ in range(1, int(input()) + 1):
    a = list(map(int, input().split(".")))
    b = list(map(str, input().split(".")))
    
    f = 1
    
    for i in range(4):
        if int(b[i], 2) != a[i]:
            f = 0
            
    print(f"Case {_}: " + ("Yes" if f else "No"))
    