from itertools import permutations

s = sorted(list(input()))

p = sorted(list(set(list(permutations(s)))))

print(len(p))

for i in p:
    print(''.join(i))