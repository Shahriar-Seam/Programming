x, a, b = map(int, input().split())

if (b <= a):
    print("delicious")
elif (x >= (b - a)):
    print("safe")
else:
    print("dangerous")