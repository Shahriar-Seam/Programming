s = input()

f = 1

if s[0] == 'A' and 'a' <= s[1] <= 'z' and s[2:-1].count('C') == 1:
    for c in s[1:]:
        if c != 'C' and 'A' <= c <= 'Z':
            f = 0
else:
    f = 0
    
print("AC" if f else "WA")