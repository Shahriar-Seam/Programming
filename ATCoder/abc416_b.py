s = input()

i = 0
while i < len(s):
    if s[i] == '.':
        s = s[:i] + 'o' + s[i+1:]
        
        while i < len(s) and s[i] != '#':
            i += 1
    else:
        i += 1
        
print(s)