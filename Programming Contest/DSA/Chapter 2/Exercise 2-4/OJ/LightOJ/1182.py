for i in range(1, int(input()) + 1):
    n = int(input())
    b = list(bin(n))
    
    cnt = b.count('1')
    
    if (cnt % 2 == 0):
        print(f"Case {i}: even")
    else:
        print(f"Case {i}: odd")