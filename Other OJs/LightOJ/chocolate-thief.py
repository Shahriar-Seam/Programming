for _ in range(1, int(input()) + 1):
    n = int(input())
    
    l = []
    
    for i in range(n):
        a = list(map(str, input().split(" ")))
        l.append((int(a[1]) * int(a[2]) * int(a[3]), a[0]))
        
    l.sort()
    
    a, b = l[0], l[-1]
    
    print(f"Case {_}:", end=" ")
    
    if a[0] < b[0]:
        print(f"{b[1]} took chocolate from {a[1]}")
    else:
        print("no thief")
    