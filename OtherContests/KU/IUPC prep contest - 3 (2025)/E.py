n = int(input())
x = list(map(int, input().split()))

sum = 0
max_sum = max(x)

for i in x:
    sum += i
    
    max_sum = max(max_sum, sum)
    
    if sum < 0:
        sum = 0
        
        
print(max_sum)