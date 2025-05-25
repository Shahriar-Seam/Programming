for _ in range(1, int(input()) + 1):
    a, b, c, d = sorted(list(map(int, input().split())))
    
    if a == d:
        print("square")
    elif a == b and c == d:
        print("rectangle")
    elif a + b + c > d:
        print("quadrangle")
    else:
        print("banana")