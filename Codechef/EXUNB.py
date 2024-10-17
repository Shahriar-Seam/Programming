for _ in range(1, int(input()) + 1):
    n = int(input())
    
    if n % 2 == 0:
        print("NO")
    else:
        a = [['0' for i in range(n)] for j in range(n)]
        
        for i in range(n):
            for j in range(1, n // 2 + 1):
                a[i][(i + j) % n] = '1'
                
        print("YES")
        for i in a:
            print(''.join(i))