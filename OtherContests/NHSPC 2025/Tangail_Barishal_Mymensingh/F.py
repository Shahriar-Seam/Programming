import math

for _ in range(1, int(input()) + 1):
    n = int(input())
    arr = list(map(int, input().split()))
    
    sorted_arr = sorted(arr)
    indices = {}
    
    for i in range(n):
        indices[arr[i]] = i
        
    swaps = 0
    
    for i in range(n):
        if sorted_arr[i] != arr[i]:
            index = indices[sorted_arr[i]]
            
            arr[i], arr[index] = arr[index], arr[i]
            
            indices[arr[i]] = i
            indices[arr[index]] = index
            
            swaps += 1
    
    print(swaps)