s = input()

l = []

for i in range(len(s)):
    if s[i] == '#':
        l.append(i + 1)

for i in range(0, len(l), 2):
    print(f"{l[i]},{l[i + 1]}")