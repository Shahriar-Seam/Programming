q = int(input())

b = []

for _ in range(q):
    l = list(map(int, input().split()))
    
    if len(l) == 1:
        print(b[0])
        
        b.pop(0)
    else:
        b.append(l[1])
        
    b.sort()