n = int(input())
n += 1

while len(set(str(n))) < 4:
    n += 1

print(n)