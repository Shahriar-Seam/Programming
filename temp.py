import string

s = string.ascii_lowercase * 26

for _ in range(int(input())):
    n, k = map(int, input().split())
    
    print(s[:n * k])