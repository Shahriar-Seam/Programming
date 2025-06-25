x, y = map(int, input().split())

sums = []
subs = []

for i in range(1, 7):
    for j in range(1, 7):
        sums.append([i + j, i, j])
        subs.append([abs(i - j), i, j])
        
bamboo = set()

for item in sums:
    if item[0] >= x:
        bamboo.add(tuple([item[1], item[2]]))
        
for item in subs:
    if item[0] >= y:
        bamboo.add(tuple([item[1], item[2]]))
        
print(f"{len(bamboo) / 36:.12f}")