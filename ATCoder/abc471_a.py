a, b = map(int, input().split())

print("Nine" if 9 in {a + b, a - b, a * b, a / b} else "Nein")