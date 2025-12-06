n = int(input())
a = list(map(int, input().split()))

count = 0

for l in range(n):
    for r in range(l, n):
        f = 1
        s = sum(a[l : r + 1])
        
        for i in range(l, r + 1):
            if s % a[i] == 0:
                f = 0
                
                break
            
        count += f
        
print(count)