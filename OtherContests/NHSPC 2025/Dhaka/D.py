for _ in range(1, int(input()) + 1):
    s = input()
    
    count = 0
    cnt = 0
    
    if s == '0' or s == '00':
        count = 1
    
    left = 0
    right = 0
    
    for i in range(len(s)):
        if s[i] == '1':
            break
        else:
            left += 1
        
    for i in range(len(s) - 1, 0, -1):
        if s[i] == '1':
            break
        else:
            right += 1
    
    if s.count('1') > 0:
        count += (left + 1) // 3 + (right + 1) // 3
    else:
        count += (left + 2) // 3
    
    for i in range(left, len(s) - right):
        if s[i] == '0':
            cnt += 1
        else:
            count += (cnt // 3)
            cnt = 0
    
    count += (cnt // 3)
    
    print(count)