import math
import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def number_of_divisors(n):
    r = math.sqrt(n)
    cnt = 0

    if r.is_integer():
        cnt -= 1

    r = int(r)

    for i in range(1, r + 1):
        cnt += 2 * (n % i == 0)
    
    return cnt

n = int(input())
a = list(map(int, input().split()))

g = math.gcd(*a)

print(number_of_divisors(g))