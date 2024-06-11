import io, os, sys, math

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

max_size = 1000005
primeCount = [0] * max_size

def sieve():
    primes = [True] * 1000005
    root = int(math.sqrt(max_size))
    
    for i in range(4, max_size, 2):
        primes[i] = False
    
    primes[0] = False
    primes[1] = False
    
    for i in range(3, root, 2):
        if primes[i] == True:
            for j in range(i * i, max_size, i + i):
                primes[j] = False
                
    for i in range(2, max_size):
        primeCount[i] = (primes[i] == True) + primeCount[i - 1]
        
sieve()

n = int(input())
arr = list(map(int, input().split()))

for num in arr:
    s = str(primeCount[num] - primeCount[int(math.sqrt(num))] + 1) + "\n"
    sys.stdout.write(s)