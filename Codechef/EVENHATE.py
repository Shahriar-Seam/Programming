from collections import deque

for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    
    count = 0
    
    for i in a:
        count += (i % 2 == 1)
        
    print(0 if count == 0 else 1 + n - count + (count - 1) // 2)