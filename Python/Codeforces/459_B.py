import math

n = int(input())

arr = list(map(int, input().split()))

ma = max(arr)
mi = min(arr)

if (ma == mi):
    print(f"{ma - mi} {n * (n - 1) // 2}")
else:
    print(f"{ma - mi} {arr.count(ma) * arr.count(mi)}")