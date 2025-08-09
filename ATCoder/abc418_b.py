def rate(s):
    if s[0] == 't' and s[-1] == 't' and len(s) >= 3:
        return (s.count('t') - 2) / (len(s) - 2)
    else:
        return 0

s = input()

n = len(s)

substrings = [s[i:j] for i in range(n) for j in range(i + 1, n + 1)]

print(max(rate(sub) for sub in substrings))