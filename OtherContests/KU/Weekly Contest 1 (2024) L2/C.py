from math import log10

a, b, c, d = map(int, input().split())

print("YES" if b * log10(a) > d * log10(c) else "NO")