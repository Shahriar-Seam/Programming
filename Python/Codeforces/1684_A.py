for _ in range(int(input())):
    n = input()
    
    if (int(n) < 10):
        print(n)
    elif (int(n) > 10 and int(n) < 20):
        print(n[1])
    else:
        print(min(n))