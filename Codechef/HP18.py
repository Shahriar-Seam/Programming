import math

for _ in range(1, int(input()) + 1):
    n, a, b = map(int, input().split())
    arr = list(map(int, input().split()))
    
    alice, ab, bob = [], [], []
    
    for i in arr:
        if (i % a == 0) and (i % b == 0):
            ab.append(i)
        elif i % a == 0:
            bob.append(i)
        elif i % b == 0:
            alice.append(i)
    
    print("BOB" if len(bob) + (len(ab) > 0) > len(alice) else "ALICE")