def f(n):
    s = 0

    while n:
        s += (n % 10) ** 2
        n //= 10
        
    return s

for n in range(1001):
    s = set()
    m = n
    
    while (m not in s) and (m != 1):
        s.add(m)

        m = f(m)
        
    if m == 1:
        print(n, "ok")
    # else:
    #     print(n, "not ok")
    
# m = 19
# for _ in range(50):
#     print(m)
    
#     m = f(m)