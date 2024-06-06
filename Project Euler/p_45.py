triangular = []
pentagonal = []
hexagonal = []

for n in range(1, 1000):
    triangular.append((n * (n + 1)) // 2)
    pentagonal.append((n * (3 * n - 1)) // 2)
    hexagonal.append(n * (2 * n - 1))
    
common = set(triangular).intersection(pentagonal).intersection(hexagonal)

print(common)