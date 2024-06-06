import math

max_size = 1000000
primes = [True] * max_size

for i in range(4, max_size, 2):
    primes[i] = False

r = int(math.sqrt(max_size))

for i in range(3, r, 2):
    if (primes[i] == True):
        for j in range(i * i, max_size, i + i):
            primes[j] = False

def circle(n):
    nums = str(n)
    nums = nums + nums[0]
    nums = nums[1:]
    
    return int(nums)

def is_circular(n):
    temp = n
        
    temp = circle(temp)
    
    while (temp != n):
        if primes[temp] == False:
            return False
        else:
            temp = circle(temp)
    
    return True

cnt = 0

for i in range(2, 100):
    if (primes[i] == True):
        if is_circular(i):
            cnt += 1
            
print(cnt)