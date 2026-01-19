p, q = map(int, input().split())
x, y = map(int, input().split())

print("Yes" if min(x - p, y - q) >= 0 and max(x - p, y - q) < 100 else "No")