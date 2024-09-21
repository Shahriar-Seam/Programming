import math

for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    
    f = n - k
    
    print("YES" if (((n + 1) // 2) - ((f + 1) // 2)) % 2 == 0 else "NO")