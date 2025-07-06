n = int(input())

s = [input() for _ in range(n)]

st = set()

for i in range(n):
    for j in range(n):
        if i != j:
            st.add(s[i] + s[j])
            
print(len(st))