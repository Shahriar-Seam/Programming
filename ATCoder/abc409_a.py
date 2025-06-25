n = int(input())

s = input()
t = input()
f = 0

for i in range(n):
    if s[i] == t[i] == 'o':
        f = 1
        
print("Yes" if f else "No")