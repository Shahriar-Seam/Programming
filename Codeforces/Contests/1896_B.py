for i in range(1, int(input()) + 1):
    n = int(input())
    s = input()
    
    cnt = 0
    while ("AB" in s):
        s = s.replace("AB", "BA")
        cnt += 1
        
    print(cnt)