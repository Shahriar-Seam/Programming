n, s = map(int, input().split())
t = list(map(int, input().split()))

t.insert(0, 0)
f = 1

for i in range(1, len(t)):
    if t[i] - t[i - 1] > s:
        f = 0

print("Yes" if f else "No")