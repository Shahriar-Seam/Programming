import math

for i in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    a.sort(reverse=True)
    
    sum = 0
    
    while len(a) > 0:
        sum += a[0]
        a.pop(0)
        if (len(a) > 0):
            sum -= a[-1]
            a.pop(-1)
    
    print(sum)