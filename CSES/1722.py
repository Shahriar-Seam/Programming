import math

def binary_exponentiation(b, p):
    result = 1

    while (p > 0):
        if p & 1:
            result = result * b

        b = b * b

        p >>= 1

    return result

def fib(n):
    phi = (1 / 2 + math.sqrt(3) / 2)
    phi_c = (1 / 2 - math.sqrt(3) / 2)
    
    return int(round((1 / math.sqrt(5)) * (binary_exponentiation(phi, n) - binary_exponentiation(phi_c, n)))) % int(1e9 + 7)

print(fib(int(input())))