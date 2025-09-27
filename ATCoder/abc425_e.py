import io, os, sys

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

sys.set_int_max_str_digits(50000)

fact = [1] * 5005

for i in range(2, 5005):
    fact[i] = fact[i - 1] * i

t, m = map(int, input().split())

for _ in range(t):
    n = int(input())
    c = list(map(int, input().split()))
    s = sum(c)
    count = fact[s]
    d = 1
    
    for i in c:
        d *= fact[i]

    sys.stdout.write(str((count // d) % m) + "\n")