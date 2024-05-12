Fib = []

Fib.append(0)
Fib.append(1)

for i in range(2, 5000):
    Fib.append(Fib[i - 1] + Fib[i - 2])

for i in range(4000, 5000):
    if (len(str(Fib[i])) >= 1000):
        print(i)
        
        break