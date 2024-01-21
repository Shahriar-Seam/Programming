for _ in range(int(input())):
    n = int(input())
    
    if (n % 2050 != 0):
        print(-1)
    else:
        ans = 0
        
        n //= 2050
        
        while (n > 0):
            ans += n % 10
            
            n //= 10
        
        print(ans)