n, a, b = map(int, input().split())
s = list(input())

for i in range(a):
    s.pop(0)
    
for i in range(b):
    s.pop()

print(''.join(s))