import math as m

a = list(map(int, input().split()))
b = list(map(int, input().split()))
n = int(input())

if ((m.ceil(sum(a) / 5) + m.ceil(sum(b) / 10)) <= n):
    print("YES")
else:
    print("NO")