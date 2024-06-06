import math

t = int(input())

for _ in range (t):
    n = int(input())

    sq = int(math.sqrt(n))
    cb = int(n ** (1 / 3))
    common = int(n ** (1 / 6))

    if (((sq + 1) ** 2) == n):
        sq += 1
    elif (((sq - 1) ** 2) == n):
        sq -= 1

    if (((cb + 1) ** 3) == n):
        cb += 1
    elif (((cb - 1) ** 3) == n):
        cb -= 1

    if (((common + 1) ** 6) == n):
        common += 1
    elif (((common - 1) ** 6) == n):
        common -= 1

    result = sq + cb - common

    print(result)