n, k = map(int, input().split())
d = list(map(str, input().split()))

num = list(str(n))

while any(i in d for i in num):
    n += 1
    num = list(str(n))

print(n)