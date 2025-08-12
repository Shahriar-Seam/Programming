from sys import stdin

s = []

cnt = 1
for line in stdin:
    s.append(line.strip())
    
    cnt += 1
    
    if cnt == 9:
        break
    
cnt = 1

for line in stdin:
    s.append(line.strip())
    s.pop(0)
    
    print("FONT" + str(cnt) + ":")
    
    cnt += 1
    
    for c in s:
        print("DB", c + "B")
        
    print(";")