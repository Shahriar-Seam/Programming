n, m = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

for x in b:
    if x in a:
        a.remove(x)
        
print(*a)