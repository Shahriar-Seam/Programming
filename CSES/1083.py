n = int(input())
a = list(map(int, input().split()))

a.sort()

j = 1
for i in a:
    if j != i:        
        break
    
    j += 1

print(j)