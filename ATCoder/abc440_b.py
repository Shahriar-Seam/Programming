n = int(input())
a = list(map(int, input().split()))

b = a.copy()
b.sort()

print(f"{a.index(b[0]) + 1} {a.index(b[1]) + 1} {a.index(b[2]) + 1}")