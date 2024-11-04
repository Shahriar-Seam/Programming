import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    s = input()
    
    length = 0
    
    for i in range(n):
        if s[i] == s[0]:
            length = max(length, i + 1)
        if s[i] == s[-1]:
            length = max(length, n - i)
            
    print(length)