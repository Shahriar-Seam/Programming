n = int(input())

s = [input() for _ in range(n)]

l = input().split()

print("Yes" if s[int(l[0]) - 1] == l[1] else "No")