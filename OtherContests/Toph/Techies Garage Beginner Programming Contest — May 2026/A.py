n, m = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

s = sum(a) + sum(b)

if len(a) >= 2:
    print(s * a[0] * a[1])
else:
    print(s)