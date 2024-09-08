n = list(input())
m = list(input())

n.sort()

for i in range(len(n)):
    if n[i] != '0':
        n.insert(0, n.pop(i))
        break
    
print("OK" if n == m else "WRONG_ANSWER")