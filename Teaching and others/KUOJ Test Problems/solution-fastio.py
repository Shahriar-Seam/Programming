import io, os, sys

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

for _ in range(int(input())):
    x = int(input())
    
    sys.stdout.write(str(4 * x * x - x + 2) + "\n")