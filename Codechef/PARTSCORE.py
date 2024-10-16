from collections import deque

for _ in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    
    a = deque(arr)
    
    s = [a.pop()]
    s2 = list(a)
    a.pop()
    
    while len(s) < k:
        temp = a.pop()
        
        s.append(temp)
    
    print(max(s) + min(s) + max(s2) + min(s2))