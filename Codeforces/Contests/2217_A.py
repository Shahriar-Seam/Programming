for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    print("YES" if (sum(list(map(int, input().split()))) & 1) or ((n * k) % 2 == 0) else "NO")
    