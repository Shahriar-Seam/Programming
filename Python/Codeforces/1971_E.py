from bisect import bisect_left

for i in range(1, int(input()) + 1):
    n, k, q = map(int, input().split())
    
    signs = [0]
    minutes = [0]
    
    signs.extend(list(map(int, input().split())))
    minutes.extend(list(map(int, input().split())))
    
    while q > 0:
        d = int(input())
        
        pos = bisect_left(signs, d) - 1
        
        mins = int(minutes[pos] + ((d - signs[pos]) * (minutes[pos + 1] - minutes[pos]) // (signs[pos + 1] - signs[pos])))
        
        print(f"{mins}", end=" ")
    
        q -= 1
    
    print()