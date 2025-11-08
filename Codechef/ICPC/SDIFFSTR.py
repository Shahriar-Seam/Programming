for _ in range(1, int(input()) + 1):
    inp = list(map(str, input().split()))
    s = inp[0]
    k = int(inp[1])
    
    t = ""
    
    l = [chr(c) for c in range(ord('a'), ord('z') + 1)]
    
    for c in l:
        if c in s:
            if k > 0:
                t += c
                
                k -= 1
        else:
            t += c
            
        if len(t) == len(s):
            break
            
    print(t if len(t) == len(s) else "NOPE")