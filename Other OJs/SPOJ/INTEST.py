import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, k = map(int, input().split())

count = 0

for _ in range(n):
    t = int(input())
    
    count += (t % k == 0)
    
print(count)