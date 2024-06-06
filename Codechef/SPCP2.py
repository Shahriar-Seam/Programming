import math

for i in range(1, int(input()) + 1):
    x, n = list(map(int, input().split()))
    
    print(max(math.ceil((n - (100 * x)) / 100), 0))