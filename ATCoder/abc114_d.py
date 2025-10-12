primes = [2]

def is_prime(n):
    i = 3
    
    while i * i <= n:
        if n % i == 0:
            return False
        
        i += 2
        
    return True

for i in range(3, 100, 2):
    if (is_prime(i)):
        primes.append(i)

fact = [0] * 101

n = (int(input()))

for prime in primes:
    p = prime
    
    while p <= n:
        fact[prime] += n // p
        p *= prime

c_2, c_4, c_14, c_24, c_74 = 0, 0, 0, 0, 0

for f in fact:
    if f >= 74:
        c_74 += 1
    if f >= 24:
        c_24 += 1
    if f >= 14:
        c_14 += 1
    if f >= 4:
        c_4 += 1
    elif f >= 2:
        c_2 += 1

print(c_74 + c_24 * (c_4 + c_2 - 1) + c_14 * (c_4 - 1) + ((c_4 * (c_4 - 1)) // 2) * c_2 + ((c_4 * (c_4 - 1) * (c_4 - 2)) // 6) * 3)