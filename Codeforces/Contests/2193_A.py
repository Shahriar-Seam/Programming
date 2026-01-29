for _ in range(1, int(input()) + 1):
    n, s, x = map(int, input().split())
    k = s - sum(list(map(int, input().split())))
    print("YES" if k >= 0 and k % x == 0 else "NO")
    