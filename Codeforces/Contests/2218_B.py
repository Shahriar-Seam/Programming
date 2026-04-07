import math

for _ in range(1, int(input()) + 1):
    a = sorted(list(map(int, input().split())))
    sum = 0
    
    for i in range(6):
        sum -= a[i]
    
    sum += a[6]
    
    print(sum)