h, w = map(int, input().split())

for i in range(h):
    if i == 0 or i == h - 1:
        print("#" * w)
    else:
        print("#" + ("." * (w - 2)) + "#")