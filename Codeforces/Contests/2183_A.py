import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    print("Bob" if a[0] == 0 and a[-1] == 0 else "Alice")