for i in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    
    print("YES" if (((a + b) % 3 == 0) and min(a, b) * 2 >= (max(a, b))) else "NO")