def possible(m, a, b, k, n):
    for i in range(n):
        if m * a[i] - b[i] >= 0:
            k -= m * a[i] - b[i]

        if k < 0:
            return 0

    return 1

n, k = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

r, l = int(1e20), 0

cookies = 0

while l <= r:
    m = (l + r) // 2

    if possible(m, a, b, k, n):
        cookies = m
        l = m + 1
    else:
        r = m - 1

print(cookies)