n, m = map(int, input().split())

print("Yes" if sum(list(map(int, input().split()))) <= m else "No")