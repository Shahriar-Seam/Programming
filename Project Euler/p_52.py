def check(n):
    return list(str(n)) == list(str(2 * n)) == list(str(3 * n)) == list(str(4 * n)) == list(str(5 * n)) == list(str(6 * n))

for i in range(0, 10):
    if (check(i)):
        print(i)