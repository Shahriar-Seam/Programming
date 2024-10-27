from itertools import permutations

def check(p):
    k = 0
    for i in range(len(p)):
        if i % 2 == 0:
            k &= p[i]
        else:
            k |= p[i]
            
    return k == 15

l = [i for i in range(1, 12)]

p = permutations(l, 11)

for i in list(p):
    if (check(i)):
        print(i)