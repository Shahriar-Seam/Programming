n = int(input())
a = sorted(list(map(int, input().split())))
k = int(input())

count = 0

for i in a:
    if i >= k:
        count += 1

print(count)