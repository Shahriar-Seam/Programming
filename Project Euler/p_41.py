import math

import math

max_size = 32000
marked = [True] * max_size
primes = []

def sieve():
    for i in range(4, max_size, 2):
        marked[i] = False

    r = int(math.sqrt(max_size))

    for i in range(3, r, 2):
        if (marked[i] == True):
            for j in range(i * i, max_size, i + i):
                marked[j] = False

    primes.append(2)
    
    for i in range(3, max_size, 2):
        if (marked[i] == True):
            primes.append(i)

def is_pandigital(n, d):
    return ('0' not in str(n)) and (len(set(str(n))) == d) and (max(str(n)) == str(d))

sieve()

def is_prime(n):    
    for i in primes:
        if n % i == 0:
            return False
        if i * i > n:
            return True
        
    return True

for i in range(987654321, 100000000, -1):
    if is_pandigital(i, 9):
        if is_prime(i):
            print(i)
            
            break