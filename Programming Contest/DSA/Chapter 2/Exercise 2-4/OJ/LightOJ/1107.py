for i in range (1, int(input()) + 1):
    x1, y1, x2, y2 = list(map(int, input().split()))
    
    print(f"Case {i}:")
    for _ in range (int(input())):
        x, y = list(map(int, input().split()))
        
        if (x > x1 and x < x2 and y > y1 and y < y2):
            print("Yes")
        else:
            print("No")