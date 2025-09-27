n, q = map(int, input().split())
a = list(map(int, input().split()))

a = a + a
pref = [0] * (2 * n + 1)
c = 0

for i in range(1, 2 * n + 1):
    pref[i] = pref[i - 1] + a[i - 1]

for _ in range(q):
    op = list(map(int, input().split()))

    if op[0] == 1:
        c += op[1]
        
        c %= n
    else:
        print(pref[c + op[2]] - pref[c + op[1] - 1])