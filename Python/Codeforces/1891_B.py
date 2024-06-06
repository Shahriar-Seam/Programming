for _ in range(1, int(input()) + 1):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    brr = list(map(int, input().split()))
    
    qrr = []
    
    for i in brr:
        if i not in qrr:
            qrr.append(i)
            
    for i in qrr:
        temp = int(pow(2, i))
        
        for j in range(n):
            if arr[j] % temp == 0:
                arr[j] += (temp // 2)
                
    for i in arr:
        print(i, "", end="")
        
    print("")