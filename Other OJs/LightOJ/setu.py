import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    sum = 0
    
    print(f"Case {_}:")
    
    for _ in range(n):
        a = list(map(str, input().split()))
        
        if len(a) == 2:
            sum += int(a[1])
        else:
            print(sum)
    