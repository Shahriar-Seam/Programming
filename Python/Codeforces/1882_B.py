for _ in range(int(input())):
    n = int(input())
    sets = []
    universal_set = set()
    elements = 0

    for i in range(n):
        s = list(map(int, input().split()))
        s.pop(0)
        s = set(s)
        sets.append(s)
        
        universal_set |= s
    
    for n in universal_set:
        big_set = set()
        
        for s in sets:
            if n not in s:
                big_set |= s
        
        elements = max(elements, len(big_set))

    print(elements)