for _ in range(int(input())):
    s = input()
    f = 0
    
    if "\\0" in s:
        s = s.replace("\\0", " ")
    else:
        s += " "
        f = 1
    
    print(len(s) - f + 1, s.index(" "))