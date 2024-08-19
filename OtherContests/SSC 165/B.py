import math

n = int(input())

a = list(map(int, input().split()))

l = math.gcd(*a)

b = bin(l)[::-1]

count = 0

for c in b:
    if c == '0':
        count += 1
    else:
        break
    
print(count)
    