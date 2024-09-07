h, w = map(int, input().split())

print("#" * (w + 2))

for _ in range(h):
    s = input()
    s = "#" + s + "#"
    print(s)

print("#" * (w + 2))
