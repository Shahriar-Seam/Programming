s = input()
t = input()

f = 1

for i in range(1, len(s)):
    if s[i].isupper() and s[i - 1] not in t:
        f = 0
        
print("Yes" if f else "No")