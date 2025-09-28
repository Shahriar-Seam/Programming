import io, os, sys

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

C = [[1] * 5005 for _ in range(5005)]

for i in range(2, 5005):
    for j in range(1, i):
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

t, m = map(int, input().split())

for _ in range(t):
    n = int(input())
    c = list(map(int, input().split()))
    s = sum(c)
    count = 1

    for i in c:
        count *= C[s][i]
        s -= i

    sys.stdout.write(str(count % m) + "\n")