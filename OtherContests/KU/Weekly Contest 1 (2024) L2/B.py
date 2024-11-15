n = int(input())

for i in range(n):
    print(('*' * (2 * i + 1)).center(2 * n - 1))

for i in range(n - 1, -1, -1):
    print(('*' * (2 * i + 1)).center(2 * n - 1))