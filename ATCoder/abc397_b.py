s = input()
ss = 'io' * 300

count = 0

for i in range(500):
    if i >= len(s) and (len(s) % 2 == 0):
        break
    
    if i < len(s):
        if s[i] != ss[i]:
            s = s[:i] + ss[i] + s[i:]
            count += 1
    else:
        s += 'o'
        count += 1
        
print(count)