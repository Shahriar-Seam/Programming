def subs(s, t):
    for c in t:
        if c not in s:
            return False
        
    return True

n, m = map(int, input().split())
s = input()
t = input()

q = int(input())

for _ in range(q):
    w = input()
    
    print("Unknown" if subs(s, w) and subs(t, w) else "Aoki" if subs(t, w) else "Takahashi" if subs(s, w) else "Unknown")