import math

def digit_sum(n):
    num = list(map(int, str(n)))
    sum = 0
    
    for i in num:
        sum += math.factorial(i)
    
    return sum

for i in range(3, 5000000):
    if (i == digit_sum(i)):
        print(i)