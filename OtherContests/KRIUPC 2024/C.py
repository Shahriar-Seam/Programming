n = int(input())

ans = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    ans[i][0] = -i
    ans[i][i] = i

for i in range(2, n + 1):
    for j in range(1, i):
        ans[i][j] = (j * ans[i - 1][j] + (i - j) * ans[i - 1][j - 1]) / i
    
print(*ans[n])