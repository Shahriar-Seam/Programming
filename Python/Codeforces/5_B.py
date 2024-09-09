from sys import stdin

strings = []
max_len = 0

for line in stdin:
    strings.append(line[0:-1])
    
    max_len = max(max_len, len(strings[-1]))
    
print("*" * (max_len + 2))

for s in strings:
    print("*" + s.center(max_len) + "*")

print("*" * (max_len + 2))
