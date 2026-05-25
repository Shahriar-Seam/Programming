n = int(input())
a = list(map(int, input().split()))
k = list(map(int, input().split()))

for i in k:
    for j in range(i):
        a[j] = -a[j]
        
print(a)

print(sum(a))