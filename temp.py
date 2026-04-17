n = int(input())

f = n > 1

if n > 2:
    for i in range(2, int(n ** .5 + 1)):
        if n % i == 0:
            f = 0
            break

print("YES" if f else "NO")