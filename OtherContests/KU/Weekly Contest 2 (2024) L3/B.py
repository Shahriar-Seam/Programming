from itertools import permutations, combinations

n = int(input())
l = [1, 1, 2, 3, 4]
s = set()

for i in permutations(l, n):
    s.add(i)
    
s = list(s)
s.sort()

print(len(s))

print(*s)

for i in range(1, n + 1):
    cnt = 0
    for j in s:
        if j[0] == i:
            cnt += 1
            
    print(i, cnt)