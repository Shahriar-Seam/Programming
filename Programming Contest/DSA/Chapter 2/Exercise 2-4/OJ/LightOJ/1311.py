for i in range(1, int(input()) + 1):
    v1, v2, v3, a1, a2 = list(map(float, input().split()))
    
    t1 = v1 / a1
    t2 = v2 / a2
    t3 = t1
    
    if (t1 < t2):
        t3 = t2
    
    bird = v3 * t3
    train = v1 * t1 - .5 * a1 * t1 * t1
    train += v2 * t2 - .5 * a2 * t2 * t2
    
    print(f"Case {i}: {train} {bird}")