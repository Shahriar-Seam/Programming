def f(n):
    b = bin(n).removeprefix("0b")
    cnt = 0
    
    for i in range(len(b) - 1, 0, -1):
        if b[i] == '1':
            break
        
        cnt += 1
        
    b = "0" * cnt + b
    
    if n == 0 or ((n & (n - 1)) and b == b[::-1] and not (not (n & (n + 1)) and (len(b) & 1))):
        s = b.strip('0')
        
        if (len(s) & 1) and s[len(s) // 2] == '1':
            return False
        else:
            return True
    else:
        return False

for _ in range(1, int(input()) + 1):
    n = int(input())
        
    print("YES" if f(n) else "NO")