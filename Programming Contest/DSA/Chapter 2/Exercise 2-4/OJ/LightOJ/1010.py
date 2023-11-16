import math

for i in range(1, int(input()) + 1):
    m, n = map(int, input().split())

    if m == 1 or n == 1:
        print(f"Case {i}: {max(m, n)}")
    elif m == 2 or n == 2:
        ans = (m * n) // 2 + ((m * n) % 8 // 2)
        print(f"Case {i}: {ans}")
    else:
        print(f"Case {i}: {math.ceil(m * n / 2)}")
