a, b, c, x = map(int, input().split())

print(0 if x > b else 1 if x <= a else c / (b - a))