drinks = {'VODKA', 'CHAMPAGNE', 'BRANDY', 'ABSINTH', 'BEER', 'WINE', 'GIN', 'RUM', 'WHISKEY', 'TEQUILA', 'SAKE'}

count = 0

for _ in range(int(input())):
    s = input()
    
    if s.isdecimal() and int(s) < 18:
        count += 1
    elif s in drinks:
        count += 1
        
print(count)