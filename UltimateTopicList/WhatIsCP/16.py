import math

N = 3005
R = int(math.sqrt(N))
primes = [1] * N

def sieve():
    for i in range(2, N, 2):
        primes[i] = 2
    
    for i in range(3, R, 2):
        if primes[i] == 1:

            for j in range(i * i, N, i + i):
                if primes[j] == 1:
                    primes[j] = i

def almost_prime(n):
    factors = set()

    while (primes[n] != 1):
        factors.add(primes[n])
        n //= primes[n]
    
    if n > 1:
        factors.add(n)
    
    return len(factors) == 2

sieve()

n = int(input())
cnt = 0

for i in range(1, n + 1):
    cnt += 1 if almost_prime(i) else 0

print(cnt)
