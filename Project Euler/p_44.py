from bisect import bisect_left

pentagons = []

for i in range(1, 1000):
    pentagons.append((i * (3 * i - 1)) // 2)
    
min_val = 100000000000000
l = len(pentagons)

for i in range(l):
    for j in range(i + 1, l):
        m = pentagons[i]
        n = pentagons[j]
        
        i1 = bisect_left(pentagons, m + n)
        i2 = bisect_left(pentagons, n - m)
        
        if (i1 < l and i2 < l) and (pentagons[i1] == m + n) and (pentagons[i2] == (n - m)):
            print(m, n)
            min_val = min(min_val, n - m)
            
print(min_val)