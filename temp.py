from itertools import permutations
input()
l, r = map(int, input().split())

n = [i for i in range(l, r + 1)]
m = n.copy()

max_o = 0

print(*n)

for i in permutations(n):
    o = 0
    
    for j in range(r - l + 1):
        o += (i[j] | m[j])
        
    max_o = max(max_o, o)
    
    # print(o)
    
print("max =", max_o)

for i in permutations(n):
    o = 0
    
    for j in range(r - l + 1):
        o += (i[j] | m[j])
    
    if o == max_o:
        print(o)
        print(*i)