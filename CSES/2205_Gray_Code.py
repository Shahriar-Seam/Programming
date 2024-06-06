length = int(input())

n = 1 << length

for i in range(n):
    s = bin(i).replace("0b", "")
    
    if len(s) < length:
        j = length - len(s)
        
        for j in range(j, 0, -1):
            print("0", end="")
            
    print(s)