def f(n):
    return sum([int(i) for i in str(n)])

a = [1]

for i in range(105):
    s = 0
    
    for j in range(i + 1):
        s += f(a[j])
        
    a.append(s)

print(a[int(input())])