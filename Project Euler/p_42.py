import math

f = open("words.txt", "r")

def str_val(s):
    sum = 0
    
    for c in s:
        sum += ord(c) - ord('A') + 1
        
    return sum + 54

cnt = 0

for s in f:
    n = str_val(s)
    
    if ((1 + math.sqrt(1 + 8 * n)) / 2).is_integer():
        cnt += 1
        
print(cnt)

f.close()