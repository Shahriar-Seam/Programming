from collections import Counter

n = int(input())

mp = Counter()

count = 0

for i in range(1 << n):
    b = bin(i).replace('0b', '')
    b = ('0' * (n - len(b))) + b
    
    
    if b.count('1') == b.count('0') - 1:
        # print(b)
        count += 1
    
print(count)