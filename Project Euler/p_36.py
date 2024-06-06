sum = 0

for i in range(1, 1000000):
    d = str(i)
    b = bin(i).removeprefix("0b")
    
    if (d == d[::-1] and b == b[::-1]):
        sum += i
        
print(sum)