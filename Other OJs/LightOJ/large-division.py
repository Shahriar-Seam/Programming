for _ in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    
    print(f"Case {_}:", "divisible" if (a % b == 0) else "not divisible")