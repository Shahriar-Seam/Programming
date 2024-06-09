import math

for i in range(1, int(input()) + 1):
    a, b, c = map(float, input().split())
    
    A = math.degrees(math.asin(a))
    B = math.degrees(math.asin(b))
    C = math.degrees(math.asin(c))
    
    if (A + B + C < 180):
        A = 180 - B - C
    
    print(round(max(A, B, C)))