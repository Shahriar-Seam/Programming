for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    c = [i for i in range(1, n + 1)]
    a.sort()
    b = []

    for i in range(n):
        b.append(c[i] - a[i])

    f = 1

    for i in b:
        if i < 0:
            f = 0
            break
    
    print("YES" if f else "NO")