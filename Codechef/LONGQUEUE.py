for _ in range(1, int(input()) + 1):
    n = int(input())
    a = list(map(int, input().split()))
    s = a.pop() // 2
    
    while len(a) > 0 and a[-1] <= s:
        a.pop()
        
    print(len(a) + 1)