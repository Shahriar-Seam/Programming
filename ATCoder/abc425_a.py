s = 0

for i in range(1, int(input()) + 1):
    s += ((-1) ** i) * (i ** 3)
    
print(s)