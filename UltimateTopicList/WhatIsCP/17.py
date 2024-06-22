K, S = map(int, input().split())

cnt = 0

for i in range(K + 1):
    for j in range(K + 1):
        k = S - i - j

        if k <= K and k >= 0:
            cnt += 1

print(cnt)