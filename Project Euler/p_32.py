def is_pan(a, b, c):
    s = set(list(map(int, (str(a) + str(b) + str(c)))))
    
    # print(s)
    
    return (len(s) == 9 and (0 not in s))

pans = []

# print(is_pan(39, 186, 7254))
n = 1000000000
for i in range(1, n):
    for j in range(1, n):
        if (len(str(i * j)) > 9):
            break
        
        if is_pan(i, j, i * j):
            pans.append(i * j)
            
            
p = list(set(pans))
p.sort()
print(p)
print(sum(set(pans)))