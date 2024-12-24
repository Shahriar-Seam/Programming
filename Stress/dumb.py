from math import gcd

for _ in range(int(input())):
    l, r, g = map(int, input().split())
    
    a, b = -1, -1
    max_dist = 0
    
    for i in range(l, r + 1):
        for j in range(r, l - 1, -1):
            if (gcd(i, j) == g):
                if a == -1:
                    a, b = i, j
                    max_dist = j - i
                elif j - i == max_dist and i < a:
                    a, b = i, j
                elif j - i > max_dist:
                    a, b = i, j
                    max_dist = j - i
    
    print(a, b)