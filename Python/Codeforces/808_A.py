n = input()

print(1 if int(n) < 10 else int(str(int(n[0]) + 1) + '0' * (len(n) - 1)) - int(n))