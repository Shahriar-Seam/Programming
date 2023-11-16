import math as m

for _ in range (int(input())):
    k = int(input())
    
    n = (3 + m.sqrt(8 * k - 7)) / 2
    
    if (n.is_integer()):
        print(1)
    else:
        print(0)