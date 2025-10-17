n = int(1e6)
sum = 0

for i in range(1, n + 1):
    sum += (n // i) + i - 1
    
print(len(str(sum)))