import math

for _ in range(1, int(input()) + 1):
    s = input()
    
    if s.count('Y') > 1:
        print("NO")
    else:
        print("YES")