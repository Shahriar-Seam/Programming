from math import comb

a, b = map(int, input().split())

print(comb(a + 2 * b - 1, 2 * b) % int(1e9 + 7))