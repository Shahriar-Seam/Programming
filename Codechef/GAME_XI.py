import math

for i in range(1, int(input()) + 1):
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    A.sort(reverse=True)
    B.sort(reverse=True)
    
    if (m < 4 or n < 4 or (m + n < 11)):
        print(-1)
    else:
        skill = A[0] + A[1] + A[2] + A[3] + B[0] + B[1] + B[2] + B[3]
        
        A.pop(0)
        A.pop(0)
        A.pop(0)
        A.pop(0)
        
        B.pop(0)
        B.pop(0)
        B.pop(0)
        B.pop(0)
        
        C = A + B
        
        C.sort(reverse=True)
        i = 0
        
        while (i < 3):
            skill += C[i]
            
            i += 1
                
        print(skill)