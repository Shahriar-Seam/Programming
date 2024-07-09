for _ in range(int(input())):
    n, k = map(int, input().split())

    if k == 1:
        print("YES")
    elif (k + (k * (k + 1)) // 2) <= n:
        print("YES")
    else:
        print("NO")