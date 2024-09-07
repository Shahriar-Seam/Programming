import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    a = map(int, input().split())
    
    print(math.gcd(*a))