x, y = map(int, input().split())

count = 0

pos = x

while pos < y:
    count += 1
    pos += x
    
print(count)