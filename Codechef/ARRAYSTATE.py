from collections import deque

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = deque(map(int, input().split()))
    
    for i in range(k):
        a.append(a.popleft() + a.pop())
        
    print(*a)