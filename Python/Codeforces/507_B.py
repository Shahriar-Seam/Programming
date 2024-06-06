import math as m

r, x, y, x1, y1 = map(int, input().split())

print(m.ceil(m.sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)) / (2 * r)))