from math import sin, pi

v, s = map(int, input().split())

r = s / (2 * sin(pi / v))

print(pi * r * r)