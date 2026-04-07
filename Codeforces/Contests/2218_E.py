import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    v = 0
    
    for i in a:
        for j in a:
            v = max(v, i ^ j)
    
    print(v)