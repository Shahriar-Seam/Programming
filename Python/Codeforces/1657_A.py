import math as m

for _ in range (int(input())):
    a = list(map(int, input().split()))
    x = a[0]
    y = a[1]
    d = m.sqrt(x ** 2 + y ** 2)
    
    if (x == 0 and y == 0):
        print(0)
    elif (d.is_integer()):
        print(1)
    else:
        print(2)