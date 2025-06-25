n, m = map(int, input().split())

wall = [0] * (n + 2)

for i in range(m):
    l, r = map(int, input().split())
    wall[l] += 1
    wall[r + 1] -= 1
    
for i in range(1, len(wall)):
    wall[i] += wall[i - 1]
    
print(min(wall[1:-1]))