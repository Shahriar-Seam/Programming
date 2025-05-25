for _ in range(int(input())):
    a, b, c = sorted(list(map(int, input().split())))
    
    print("OK" if a + b > c else "Wrong!!")