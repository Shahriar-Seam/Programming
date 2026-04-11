from collections import Counter

for _ in range(1, int(input()) + 1):
    s = Counter(input().lower().replace(" ", ""))
    t = Counter(input().lower().replace(" ", ""))
    
    print(f"Case {_}: " + ("Yes" if s == t else "No"))