import math

def digit_fact(n):
    temp = n
    s = sum([math.factorial(i) for i in list(map(int, str(temp)))])
    cnt = 1
    l = []
    
    while (s not in l):
        l.append(s)
        
        temp = s
        s = sum([math.factorial(i) for i in list(map(int, str(temp)))])
        
        cnt += 1
    
    return cnt

cnt = 0

for i in range(1, 1000000):
    terms = digit_fact(i)
    
    if (terms == 60):
        cnt += 1

print(cnt)