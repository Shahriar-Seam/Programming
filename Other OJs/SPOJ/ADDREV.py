import math

for _ in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    
    print(int(str(int(str(a)[::-1]) + int(str(b)[::-1]))[::-1]))