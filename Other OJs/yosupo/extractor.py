from sys import stderr

s = input()

print(s, file=stderr)

n = list(map(int, s.split()))[1]

print(input(), file=stderr)

for _ in range(n):
    print(input(), file=stderr)