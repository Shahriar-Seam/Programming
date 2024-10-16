import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    
    count = 0
    
    for i in range(n, 0, -2):
        count += i ** 2
        
    print(count)