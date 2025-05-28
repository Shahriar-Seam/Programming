r, k, d = map(int, input().split())

if r == k:
    print("Draw 0")
elif r > k:
    print("Rahim", d // (r - k))
else:
    print("Karim", d // (k - r))