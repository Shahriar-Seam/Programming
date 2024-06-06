import math

for i in range(1, int(input()) + 1):
    x = int(input())
    
    print(100 - (math.ceil(x / 10) * 10))