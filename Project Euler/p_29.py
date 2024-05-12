nums = []

for i in range(2, 101):
    for j in range(2, 101):
        nums.append(i ** j)
        nums.append(j ** i)
        
print(len(set(nums)))