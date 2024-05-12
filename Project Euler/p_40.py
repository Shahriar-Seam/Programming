s = ""
i = 1

while (len(s) < 1000005):
    s = s + str(i)
    i += 1
    
champernownes_constant = 1

i = 1

while (i <= 1000000):
    champernownes_constant *= int(s[i - 1])
    
    i *= 10

print(champernownes_constant)