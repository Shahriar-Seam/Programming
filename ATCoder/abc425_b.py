n = int(input())
a = list(map(int, input().split()))
l = [i for i in range(1, n + 1)]
f = 1

for i in a:
    if i != -1:
        if i in l:
            l.remove(i)
        else:
            f = 0

if not f:
    print("No")
else:
    for i in range(n):
        if a[i] == -1:
            a[i] = l.pop()
    print("Yes")
    print(*a)