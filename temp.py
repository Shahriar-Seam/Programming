for _ in range(int(input())):
    n, x = map(int, input().split())
    print(len([i for i in list(map(int, input().split())) if i >= x]))