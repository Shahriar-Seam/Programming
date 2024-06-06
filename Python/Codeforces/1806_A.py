for i in range(1, int(input()) + 1):
    a, b, c, d = list(map(int, input().split()))
    
    ans = abs(abs(d - b) + a + abs(d - b) - c)
    
    if ((d - b) < 0):
        print(-1)
    elif (c - a > d - b):
        print(-1)
    else:
        print(ans)