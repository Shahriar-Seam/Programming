for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    temp = a[0]
    a.pop(0)
    a.append(temp)
    
    print(*a)