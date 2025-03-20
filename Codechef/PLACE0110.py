import math

for _ in range(1, int(input()) + 1):
    x, y = map(int, input().split())
    
    print(2 * min(x, y) + max(0, (max(x, y) - min(x, y)) * 2 - 1))