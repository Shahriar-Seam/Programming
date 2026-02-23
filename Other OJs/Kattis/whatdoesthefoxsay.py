for _ in range(1, int(input()) + 1):
    sounds = list(input().split())
    
    while True:
        s = list(input().split())
        
        if s[-1][-1] == '?':
            print(*sounds)
            
            break
        else:
            while s[-1] in sounds:
                sounds.remove(s[-1])
    