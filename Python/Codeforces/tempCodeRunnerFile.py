import math

def prime(n):
    for i in range(2, math.ceil(math.sqrt(n)) + 1):
        if (n % i == 0):
            return False
    return True

t = int(input())

for _ in range(t):
    n = int(input())
    
    if (n == 1):
        print("FastestFinger")
    elif (n == 2):
        print("Ashishgup")
    elif (n % 2 == 1):
        print("Ashishgup")
    elif math.log2(n).is_integer():
        print("FastestFinger")
    elif prime(n // 2):
        print("FastestFinger")
    else:
        print("Ashishgup")
