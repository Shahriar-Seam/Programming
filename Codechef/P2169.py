for _ in range(int(input())):
    n = int(input())
    s = input()
    ss = ""
    
    for c in s:
        if c == '0':
            ss += '1'
        else:
            ss += '0'
            
    print(ss)