import math

for _ in range(int(input())):
    n = int(input())
    sum = (n * (n + 1)) // 2

    l = int(math.log2(n)) + 1

    for i in range(l):
        sum -= 2 * 2 ** i

    print(sum)