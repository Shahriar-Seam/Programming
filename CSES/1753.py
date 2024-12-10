s1 = input()
s2 = input()

count = 0

for i in range(len(s1)):
    if s2 == s1[i:i+len(s2)]:
        count += 1
        
print(count)