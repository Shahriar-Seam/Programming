for _ in range(int(input())):
    n, k = map(int, input().split())
    
    b = bin(k).removeprefix("0b")[::-1]
    
    for i in range(0, len(b)):
        if b[i] == '1':
            break
    
    print(n - i)