import math as m

n = int(input())

print("SAME" if n == 2 or n == 4 else "POWER" if n * m.log(2) > 2 * m.log(n) else "SQUARE")