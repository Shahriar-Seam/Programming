for i in range(1, int(input()) + 1):
    x, y = list(map(int, input().split()))
    a, b = list(map(int, input().split()))
    
    print(min(abs(x - y) * a + min(x, y) * b, x * a + y * a))