for _ in range(1, int(input()) + 1):
    f, d, a, b = map(int, input().split())
    
    t_t = ((d + f) / (0.5 * a)) ** 0.5
    t_b = f / b
    
    if (t_t <= t_b):
        print("Tiger")
    else:
        print("Bolt")