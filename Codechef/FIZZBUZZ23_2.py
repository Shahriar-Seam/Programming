t = int(input())

for _ in range(t):
    a = list(map(int, input().split()))
    
    print(int(a[0] / (a[1] * 5)) + a[2])