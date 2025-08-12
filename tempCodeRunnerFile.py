strings = [input() for i in range(8)]

matrix = [list(s) for s in strings]

transposed_matrix = [list(row) for row in zip(*matrix)]

for s in transposed_matrix:
    print("DB", ''.join(s) + 'B')