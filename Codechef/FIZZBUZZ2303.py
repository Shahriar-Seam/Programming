import math

t = int(input())

for _ in range(t):
    n = int(input())
    
    print(int(math.factorial(n)/(math.factorial(n - 2))))