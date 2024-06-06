for i in range(1, int(input()) + 1):
    x = int(input())
    
    if x < 3:
        print(3)
    elif x % 2 == 1:
        print(1)
    elif x & (x - 1) == 0:
        print(x + 1)
    else:
        y = 1
        
        while (x % 2 != 1):
            y *= 2
            x /= 2
        
        print(y)