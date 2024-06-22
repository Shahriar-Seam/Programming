n = input()

cnt = 0

while True:
    if (len(n) == 1):
        break
    else:
        n = str(sum(int(i) for i in n))
        cnt += 1

print(cnt)