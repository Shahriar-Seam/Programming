from itertools import permutations

s, d = input().split()

d = int(d)

for i in permutations(s, d):
    t = ''.join(i)
    
    if t[0] != '0':
        print(t)
        