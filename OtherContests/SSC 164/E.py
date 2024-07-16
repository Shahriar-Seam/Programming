import math

n, m = map(int, input().split())

days = (-1 + math.ceil(math.sqrt(1 + 8 * n))) // 2

print(days)