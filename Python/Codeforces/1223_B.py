for i in range(1, int(input()) + 1):
    s1 = set(list(input()))
    s2 = set(list(input()))
    
    if len(s1.intersection(s2)) > 0:
        print("YES")
    else:
        print("NO")