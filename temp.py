from itertools import permutations, combinations

s = "aabbc"

def valid(t):
    for i in range(len(t)):
        for j in range(len(t)):
            if t[i] == t[j] and abs(i - j) % 2 == 1:
                return False
    
    return True

dist = set()

for i in permutations(s):
    t = ''.join(i)
    
    if valid(t):
        dist.add(t)


print(dist)

print(len(dist))