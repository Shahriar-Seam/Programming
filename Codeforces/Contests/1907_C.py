for _ in range(int(input())):
    n = int(input())
    s = list(input())
    
    i = 0
    
    while i < len(s) - 1:
        if i >= 0 and s[i] != s[i + 1]:
            s.pop(i)
            s.pop(i)
            i -= 2
        i += 1
    
    print(len(s))