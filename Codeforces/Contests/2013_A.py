import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    x, y = map(int, input().split())
    
    print(math.ceil(n / min(x, y)))