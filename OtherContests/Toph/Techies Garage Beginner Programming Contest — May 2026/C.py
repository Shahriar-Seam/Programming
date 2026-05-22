n, h, a, s = map(int, input().split())

print("hungry" if (6 - n) * 10 + h * 2 + a // 5 + s // 10 >= 30 else "not hungry")