import math

for _ in range(1, int(input()) + 1):
    a, b, c = map(int, input().split())
    
    l = math.lcm(a, b)
    
    for i in range(l, c + 1, l):
        print(i)
    
    print()