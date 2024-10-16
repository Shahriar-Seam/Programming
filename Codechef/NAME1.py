from collections import Counter

for _ in range(1, int(input()) + 1):
    d, m = input().split()
    n = int(input())
    c = ""
    
    for i in range(n):
        c += input()
        
    p = Counter(d + m)
    c = Counter(c)
    
    flag = 1
    
    for item in c.items():
        if item[1] > p[item[0]]:
            flag = 0
            break
    
    print("YES" if flag == 1 else "NO")