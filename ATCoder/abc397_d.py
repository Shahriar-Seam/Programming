from math import sqrt, cbrt

n = int(input())

x, y = 0, 0

for k in range(1, int(cbrt(n) + 1)):
    y = int((-3 * k * k + sqrt(max(0, 9 * k ** 4 - 12 * k * (k ** 3 - n)))) / (6 * k))
    
    x = y + k
    
    if x ** 3 - y ** 3 == n:
        break
    elif (x + 1) ** 3 - (y + 1) ** 3 == n:
        x += 1
        y += 1
        break
    
if x == 0 or y == 0:
    print(-1)
else:
    print(x, y)