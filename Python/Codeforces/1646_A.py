t = int(input())

for _ in range (t):
    a = list(map(int, input().split()))
    n = a[0]
    s = a[1]
    
    print(int(s / (n ** 2)))