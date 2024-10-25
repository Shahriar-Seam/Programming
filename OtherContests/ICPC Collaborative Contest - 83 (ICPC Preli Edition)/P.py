mod = int(1e9 + 7)

def binex(b, p):
    result = 1
    while p > 0:
        if p & 1:
            result = (result * b) % mod
        b = (b * b) % mod
        p >>= 1
    return result

def sum(a, r, n):
    return (a * (binex(r, n) - 1) // (r - 1)) % mod

def solve():
    a, b, c, d = map(int, input().split())

    sum1 = sum((binex(2, a) * binex(3, c)) % mod, 3, d - c + 1)

    sum2 = sum(sum1, 2, b - a + 1)

    print(sum2)

t = int(input())
for _ in range(t):
        solve()
