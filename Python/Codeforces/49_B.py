def convert_10_to_b(n, b):
    num = ""
    
    while n > 0:
        num += str(n % b)
        
        n //= b
      
    return num[::-1]

def convert_b_to_10(n, b):
    num = 0
    
    n = str(n)[::-1]
    
    for i in range(len(n)):
        num += int(n[i]) * b ** i
        
    return num

a, b = map(int, input().split())

base = int(max(str(a) + str(b))) + 1

print(len(convert_10_to_b(convert_b_to_10(a, base) + convert_b_to_10(b, base), base)))