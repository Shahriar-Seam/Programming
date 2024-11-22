# n = int(input())

# print(n + 2 * (sum([1 << i for i in range(n)])))


from itertools import permutations

n = 5
l = [1, 2, 3, 4, 5] * 5
s = set()

for i in permutations(l, n):
    if sorted(i) == list(i) and i[0] != i[-1]:
        s.add(i)
    
s = list(s)
s.sort()
print(*s)

for i in range(1, n + 1):
    cnt = 0
    for j in s:
        if j[0] == i:
            cnt += 1
            
    print(i, cnt)