from itertools import permutations

for n in range(3, 10):
    l = [i + 1 for i in range(n)]

    def f(p):
        for i in range(1, n - 1):
            f = 0
            
            for j in range(i, n):
                if p[i] == p[j] ^ (i + 1):
                    f = 1
                    
            if f == 0:
                return False
                
        return True

    for p in permutations(l):
        if f(p) and (p[-1] == n or p[0] == n):
            print(*p)