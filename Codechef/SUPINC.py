import math

for i in range(1, int(input()) + 1):
    n, k, x = map(int, input().split())
    
    if (k <= n):
        k -= 1
                
        if (x > ((k * (k + 1)) // 2)):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")