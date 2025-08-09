n = int(input())
s = input()

print("Yes" if len(s) >= 3 and s[-3:] == "tea" else "No")