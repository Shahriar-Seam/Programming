def func(cnt):
    s = [list(input().strip()) for i in range(8)]

    t = [['1'] * 8 for i in range(8)]

    st = t + s + t

    # for ss in st:
    #     print(''.join(ss))
        
    for i in range(3, 17):
        if i < 9:
            temp = t[i:] + s[:i]
        else:
            temp = s[i - 8:] + t[:i - 8]
            
        print("FONT" + str(cnt) + ':')
        for j in temp:
            print("DB", ''.join(j) + 'B')
        
        print(";")
        
        cnt += 1
        
    return cnt

cnt = 1
for i in range(10):
    temp = func(cnt)
    
    cnt = temp