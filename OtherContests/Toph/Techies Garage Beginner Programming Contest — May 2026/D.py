s = input()
k = int(input())
t = ""
f = 0

for c in s:
    d = (int(c) + k) % 10
    
    t += str(d)
    
    if d in [2, 3, 5, 7]:
        f = 1
        
print(t)
print("YES" if f else "NO")