from itertools import permutations

n = 3

s = 'sp.' * n

p = sorted(list(set(list(permutations(s, n)))))

for i in p:
    print(3)
    print(''.join(i))