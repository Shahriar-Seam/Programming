from collections import Counter

for _ in range(int(input())):
    n = int(input())
    a = Counter(map(int, input().split()))
    
    max_count = 0
    max_element = 0
    
    for item in a.items():
        if item[0] != 0 and item[1] > max_count:
            max_count = item[1]
            max_element = item[0]
    
    if max_element == 0:
        a[1] = n
        a[0] = 0
    else:
        a[max_element] += a[0]
        a[0] = 0
    
    total = 0
    for i in a.values():
        total += (i * (i - 1)) // 2
        
    print(total)