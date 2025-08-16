n = int(input())

l = [list(map(int, input().split())) for i in range(n)]

x = list(c[0] for c in l)
y = list(c[1] for c in l)

x.sort()
y.sort()

xx = (x[0] + x[-1]) // 2
yy = (y[0] + y[-1]) // 2

print(max(max(abs(xx - c[0]) for c in l), max(abs(yy - c[1]) for c in l)))