s = input()

s1 = s[:len(s) // 2 + 1]
s2 = s[1:]
f = ""

for i in range(len(s1), len(s)):
    g = 1
    
    k = len(s2) - 1
    for j in range(len(s1) - 1, 0, -1):
        if s1[j] != s2[k]:
            g = 0
            break
        
        k -= 1
    
    if g == 1:
        f = s1
        break
    
    s1 += s[i]

if len(f) == 0 or len(set(s)) == 0:
    print("NO")
else:
    print("YES")
    print(f)