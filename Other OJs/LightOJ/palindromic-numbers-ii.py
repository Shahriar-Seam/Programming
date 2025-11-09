for _ in range(1, int(input()) + 1):
    n = input()
    
    print(f"Case {_}:", "Yes" if n == n[::-1] else "No")