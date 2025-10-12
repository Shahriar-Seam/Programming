def f(n):
    if n == 1:
        print(n, 1)
        
        return 1
    
    v = f(n - 1) + n
    print(n, v)
    
    return v

f(int(input()))