s, t = map(int, input().split())

triplets = 0

for i in range(s + 1):
    for j in range(s + 1):
        for k in range(s + 1):
            if i + j + k <= s and i * j * k <= t:
                triplets += 1
            else:
                break

print(triplets)