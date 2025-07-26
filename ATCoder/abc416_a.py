n, l, r = map(int, input().split())
s = input()

print("Yes" if s[l - 1 : r].count("o") == r - l + 1 else "No")