a, b, c = map(int, input().split())

s = "a*a + b*b < c*c"

print("Yes" if eval(s) else "No")