for i in range(1, int(input()) + 1):
    n, k, x = list(map(int, input().split()))
    
    sum_max = int(n * (n + 1) / 2)
    sum_min = int(k * (k + 1) / 2)
    sum_small = int((n - k) * (n - k + 1) / 2)
    sum_big = sum_max - sum_small
    
    if (x >= sum_min and x <= sum_big):
        print("YES")
    else:
        print("NO")