n, qq = map(int, input().split())

qqq = list(map(int, input().split()))

a = [0] * (n + 2)

count = 0

for q in qqq:
    a[q] ^= 1
    
    if a[q - 1 : q + 2] == [0, 1, 0] or a[q - 1 : q + 2] == [1, 0, 1]:
        count += 1
    elif a[q - 1 : q + 2] == [1, 1, 1] or a[q - 1 : q + 2] == [0, 0, 0]:
        count -= 1
        
    
    print(count)