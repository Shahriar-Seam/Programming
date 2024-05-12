s = 0

for n in range(2, 10000000):
    num = list(map(int, str(n)))

    sum = 0

    for i in num:
        sum += i ** 5
        
    if (sum == n):
        s += sum
        print(sum)
        
print(s)