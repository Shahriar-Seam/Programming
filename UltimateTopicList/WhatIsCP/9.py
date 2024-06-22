a, b, c = map(int, input().split())

i = 0
found = False

while True:
    m = a * i

    if m > c:
        break

    if ((c - m) % b == 0):
        found = True
        break
    else:
        i += 1

print("Yes" if found else "No")