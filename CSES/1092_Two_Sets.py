import math

n = int(input())
nums = [i for i in range(n, 0, -1)]

s = sum(nums)

if (s % 2 == 1):
    print("NO")
else:
    print("YES")
    temp_s = 0
    m = int((1 + math.sqrt(1 + 8 * (s // 2))) // 2)
    
    first = [i for i in range(m + 1, n + 1)]
    
    f_s = sum(first)
    carry = s // 2 - f_s
    
    if f_s != s // 2:
        first.append(carry)
    
    print(len(first))
    for i in first:
        print(i, end=" ")
        
    print()
    print(n - len(first))
    for i in range(1, m + 1):
        if (i != carry):
            print(i, end=" ")