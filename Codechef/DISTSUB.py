for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    
    if (n >= k + (k * (k + 1)) // 2) or (k == 1):
        print("YES")
    else:
        print("NO")