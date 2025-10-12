def f(a):
    return len(set(a))

a = list(map(int, input().split()))
b = [0] * len(a)

for i in range(len(a)):
    for j in range(i + 1):
        b[i] += f(a[j : i + 1])
    
print(1)
print(len(b))
print(*b)
