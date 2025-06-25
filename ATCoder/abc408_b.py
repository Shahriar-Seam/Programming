input()

s = sorted(list(set((list(map(int, input().split()))))))

print(len(s))
print(*s)