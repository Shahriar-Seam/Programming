import math

for i in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    if (a[0] == a[n - 1] and a[0] == min(a)):
        print("YES")
    else:
        print("NO")