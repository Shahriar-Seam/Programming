n = int(input())
a = list(map(int, input().split()))

cnt = 0

for i in range(1, 2 * n - 1):
    cnt += (a[i - 1] == a[i + 1])

print(cnt)