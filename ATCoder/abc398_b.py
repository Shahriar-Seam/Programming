from collections import Counter

a = Counter(list(map(int, input().split())))

val = list(a.values())

val.append(0)

val.sort(reverse=True)

print("Yes" if val[0] >= 3 and val[1] >= 2 else "No")