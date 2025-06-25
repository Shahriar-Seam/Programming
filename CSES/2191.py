n = int(input())

p = [list(map(int, input().split())) for _ in range(n)]

p.append(p[0])

plus = 0
minus = 0

for i in range(n):
    plus += p[i][0] * p[i + 1][1]
    
for i in range(n):
    minus += p[i][1] * p[i + 1][0]
    
print(abs(plus - minus))