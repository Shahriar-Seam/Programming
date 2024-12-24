def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

for _ in range(int(input())):
    l, r, g = map(int, input().split())
    max_dist = 0
    a, b = -1, -1
    temp_g = 0
    i = 0
    
    left = ((l + g - 1) // g) * g
    right = (r // g) * g
    
    if (gcd(left, right) == g):
        a, b = left, right
    
    while right >= left:
        temp_g = gcd(left, right)
        
        if temp_g == g and right - left == max_dist:
            if left < a:
                a, b = left, right
                max_dist = right - left
        
        if temp_g == g and right - left > max_dist:
            a, b = left, right
            max_dist = right - left
        
        for r1 in range(right, left - 1, -g):
            temp_g = gcd(left, r1)
            
            if temp_g == g:
                if r1 - left == max_dist and left < a:
                    a, b = left, r1
                if r1 - left > max_dist :
                    a, b = left, r1
                    max_dist = r1 - left
                break
            
            i += 1

        for l1 in range(left, right + 1, g):
            temp_g = gcd(l1, right)
            
            if temp_g == g:
                if right - l1 == max_dist and l1 < a:
                    a, b = l1, right
                if right - l1 > max_dist:
                    a, b = l1, right
                    max_dist = right - l1
                break
            
            i += 1
        
        right -= g
        left += g
        
        i += 1
        
        if i > 10000:
            break

    if (a > b):
        print(-1, -1)
    else:
        print(a, b)