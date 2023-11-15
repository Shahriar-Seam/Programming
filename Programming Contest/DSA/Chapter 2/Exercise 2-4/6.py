import math as m

n = int(input())
r = int(input())

print(int(m.factorial(n) / (m.factorial(r) * m.factorial(n - r))))