import math

max_size = 1000000
primes = [True] * max_size

primes[0] = primes[1] = False
for i in range(4, max_size, 2):
    primes[i] = False

r = int(math.sqrt(max_size))

for i in range(3, r, 2):
    if (primes[i] == True):
        for j in range(i * i, max_size, i + i):
            primes[j] = False

def l_to_r(n):
    nums = str(n)
        
    while (len(nums) > 0):
        if (primes[int(nums)] == False):
            return False
        else:
            nums = nums[1:]
    
    return True

def r_to_l(n):
    while (n > 0):
        if (primes[n] == False):
            return False
        else:
            n //= 10
    
    return True

cnt = 0
sum = 0

for i in range(10, 1000000):
    if (l_to_r(i) == True) and (r_to_l(i) == True):
        print(i)
        cnt += 1
        sum += i
        
print(cnt)
print(sum)