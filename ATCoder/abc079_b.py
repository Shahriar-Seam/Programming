l = []
l.append(2)
l.append(1)

for i in range(90):
    l.append(l[-1] + l[-2])
    
print(l[int(input())])