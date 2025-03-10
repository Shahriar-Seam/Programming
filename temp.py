t = int(input())

for n in range(1, t + 1):
    a = [i for i in range(1, n + 1) if (i % 3 == 0) or (i % 5 == 0) or (i % 7 == 0)]

    if len(a) == (n // 3 + n // 5 + n // 7 - n // 15 - n // 35 - n // 21 + n // 105):
        print(n, a, len(a))