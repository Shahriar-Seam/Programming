import math

f = open("C:\\Users\\Anonymous_HF\\Desktop\\Programming\\Project Euler\\base_exp.txt", "r")

i = 1
m = 0
line = 1

for s in f:
    a, b = map(int, s.split())
    
    if (b * math.log10(a)) > m:
        m = b * math.log10(a)
        line = i
    
    i += 1
    
print(line)