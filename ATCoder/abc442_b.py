v = 0
p = 0

for _ in range(int(input())):
    a = int(input())
    
    if a == 1:
        v += 1
    elif a == 2:
        v = max(0, v - 1)
    else:
        p ^= 1
        
    print("Yes" if v >= 3 and p else "No")