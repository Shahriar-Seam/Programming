# (cnt, [days], sum)
months = []

for _ in range(1, int(input()) + 1):
    m = list(map(int, input().split()))
    months.append((m[0], m[1 : ], sum(m[1 : ])))
    
for _ in range(1, int(input()) + 1):
    a, b, d, m, y = map(int, input().split())
    
    a -= 1
    b -= 1
    m -= 1
    y -= 1
    
    d = d + sum(months[a][1][ : m]) + months[a][2] * y
    
    y = (d + months[b][2] - 1) // months[b][2]
    
    d -= (y - 1) * months[b][2]
    
    for m in range(months[b][0]):
        if d > months[b][1][m]:
            d -= months[b][1][m]
        else:
            break
    
    m += 1
    
    print(f"Query {_}: {d} {m} {y}")