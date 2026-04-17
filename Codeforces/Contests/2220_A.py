import math

for _ in range(1, int(input()) + 1):
    input()
    a = list(map(int, input().split()))
    
    a.sort()
    
    if a == sorted(list(set(a))):
        print(*a[::-1])
    else:
        print(-1)
    