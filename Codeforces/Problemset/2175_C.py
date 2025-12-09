from collections import Counter
import heapq

def f():
    s, t = input(), input()
    s_c, t_c = Counter(s), Counter(t)

    for k in set(s_c) | set(t_c):
        if s_c[k] > t_c[k]:
            print("Impossible")
            return

    v = ''.join(sorted(k * (t_c[k] - s_c[k]) for k in t_c))

    print(''.join(heapq.merge(s, v)))

for _ in range(int(input())):
    f()
