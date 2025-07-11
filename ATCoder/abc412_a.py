count = 0

for _ in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    
    if b > a:
        count += 1
        
print(count)