import io, os, sys

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())

for i in range(t):
    a, b = map(int, input().split())
    
    sys.stdout.write(str(a * b) + "\n")