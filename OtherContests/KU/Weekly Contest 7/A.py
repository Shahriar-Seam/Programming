from itertools import permutations

n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

p = [i for i in range(n)]

sum = 0

for i in permutations(p):
    print(f"{a[i[0]]} ^ {b[0]} + {a[i[1]]} ^ {b[1]} + {a[i[2]]} ^ {b[2]}")
    
    sum += (a[i[0]] ^ b[0]) + (a[i[1]] ^ b[1]) + (a[i[2]] ^ b[2])
    
print(sum)