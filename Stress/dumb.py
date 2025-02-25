import io, os, sys, math

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def binary_exponentiation(b, p):
    result = 1;

    while (p > 0):
        if (p & 1):
            result = result * b

        b = b * b

        p >>= 1

    return result

n, x = map(int, input().split())
a = list(map(int, input().split()))

num = 0
d = max(a)
s = sum(a)
r = s - d

for i in a:
    num += binary_exponentiation(x, d - i)

num *= binary_exponentiation(x, r)

denom = binary_exponentiation(x, s)

sys.stdout.write(str(math.gcd(num, denom) % int(1e9 + 7)) + "\n")