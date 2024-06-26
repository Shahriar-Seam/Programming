for _ in range(int(input())):
    n, x, y = map(int, input().split())

    if (y > 2 * x):
        print((n // 2) * y + (n % 2) * x)
    else:
        print(n * x)