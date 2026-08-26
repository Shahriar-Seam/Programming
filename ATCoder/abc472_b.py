n = int(input())
a = list(map(int, input().split()))
s = sum(a)
p = 0
diff = int(1e18)

for i in a:
    s -= i
    p += i
    
    diff = min(diff, abs(s - p))
    
print(diff)