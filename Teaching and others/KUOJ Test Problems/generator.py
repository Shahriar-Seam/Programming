from random import randint

t = int(1e0)

print(t)

for i in range(t):
    print(randint(int(1e8), int(1e9)) * ((-1) ** randint(0, 1)))