for i in range(1, int(input()) + 1):
    n, k = list(map(int, input().split()))
    s = input()
    
    rs = "".join(reversed(s))
    
    s1 = s + rs
    s2 = rs + s
    
    if (s1 != s2 and k > 0):
        print(2)
    else:
        print(1)