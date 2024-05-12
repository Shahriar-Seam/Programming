import math
from bisect import bisect_left

max_size = 1000000
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
            
sieve()

def check(n, index):
    while (index >= 0):
        if math.sqrt((n - primes[index]) // 2).is_integer():
            return True

        index -= 1

    return False

for i in range(3, 100, 2):
    index = bisect_left(primes, i)
    
    if (primes[index] != i):
        if (check(i, index - 1)) == False:
            print(i)