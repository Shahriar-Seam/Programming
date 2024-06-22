a, b, c = map(int, input().split())

m = (b // c) * c

print(m if m >= a else -1)