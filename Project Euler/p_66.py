import math

max_x = 335159612
max_y = 42912792

for d in range(100, 200):
    if math.sqrt(d).is_integer() == True:
        continue
    
    x = 0.1
    y = 1
    
    while x.is_integer() == False:
        x = math.sqrt(1 + d * y * y)
        
        y += 1
    
    max_x = max(max_x, x)
    max_y = max(max_y, y)

print(int(max_x))
print(int(max_y))