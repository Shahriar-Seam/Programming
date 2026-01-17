import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    
    print(2 if n == 2 else 3 if n == 3 else 0 if (n % 2 == 0) else 1)