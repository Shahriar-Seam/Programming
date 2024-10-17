from collections import deque

for _ in range(1, int(input()) + 1):
    n = int(input())
    s = deque(input())
    
    t = ""
    
    i = 0
    
    while len(s) > 0:
        if i % 2 == 0:
            c = s.popleft()

            if c == '1':
                t += c
            else:
                t = c + t
        else:
            c = s.pop()

            if c == '0':
                t += c
            else:
                t = c + t
        i += 1
            
    print(t)