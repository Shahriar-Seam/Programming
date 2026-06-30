from sys import stdin

for line in stdin:
    a, b = map(int, line.split())
    
    print(abs(a - b))