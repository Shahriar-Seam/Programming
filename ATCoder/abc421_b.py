def f(x):
    return int(x[::-1])

x, y = map(int, input().split())

a = []

a.append(x)
a.append(y)

for i in range(10):
    a.append(f(str(a[-1] + a[-2])))
    
print(a[9])