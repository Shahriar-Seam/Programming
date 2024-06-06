for i in range(1, int(input()) + 1):
    w = int(input())
    
    if (w % 2 == 1):
        print(f"Case {i}: Impossible")
    else:
        m = 2
        n = w // m
        while (1):
            if ((w % m == 0) and (n % 2 == 1)):
                print(f"Case {i}: {n} {m}")
                break
            else:
                m *= 2
                n //= 2
