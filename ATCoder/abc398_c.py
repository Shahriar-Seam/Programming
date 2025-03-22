from collections import Counter

n = int(input())

l = list(map(int, input().split()))

a = Counter(l)

v = [0]

for i, j in a.items():
    if (j == 1):
        v.append(i)
      
if max(v) == 0:
    print(-1)
else:  
    print(l.index(max(v)) + 1)