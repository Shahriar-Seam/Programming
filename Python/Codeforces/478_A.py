b = sum(list(map(int, input().split()))) / 5

if (b.is_integer() and b != 0):
    print(int(b))
else:
    print(-1)