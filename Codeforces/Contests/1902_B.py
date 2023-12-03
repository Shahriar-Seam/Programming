import math as m

for i in range(1, int(input()) + 1):
    n, p, l, t = list(map(int, input().split()))
    days_on = 0
    tasks = m.ceil(n / 7)
    
    all_tasks = p - tasks * t

    while (True):
        if (p <= 0):
            print(n - days_on)
            break
        else:
            days_on += 1
            p -= (l + 2 * t)
            tasks -= 2
            if (tasks <= 0):
                t = 0