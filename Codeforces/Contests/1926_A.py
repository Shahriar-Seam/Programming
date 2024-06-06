for i in range(1, int(input()) + 1):
    s = input()
    
    if (s.count('A') > s.count('B')):
        print("A")
    else:
        print("B")