from random import choice

a = [chr(i) for i in range(ord('a'), ord('z') + 1)]

for _ in range(int(input())):
    s = input().lower()
    
    t = ""
    
    for c in s:
        t += choice([i for i in a if i != c])
    
    print(t)