import itertools

characters = ['s', 'p', '.']
length = 3

permutations = itertools.product(characters, repeat=length)

for perm in permutations:
    print(''.join(perm))