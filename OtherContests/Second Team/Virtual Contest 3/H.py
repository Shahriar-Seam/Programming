n = int(input())

while True:    
    image = []
    
    for _ in range(n):
        s = input()
        c = s[0]
        ch = []
        
        if c == '.':
            ch = ['.', '#']
        else:
            ch = ['#', '.']
        
        s = s[2:]
        
        nums = list(map(int, s.split()))
        line = []
        
        for i in range(len(nums)):
            line.append(nums[i] * ch[i % 2])
        
        image.append(''.join(line))
                
    length = len(image[0])
    f = 1
    
    for l in image:
        if len(l) != length:
            f = 0
            
            break
    
    for l in image:
        print(l)
        
    if not f:
        print("Error decoding image")
    
    n = int(input())
    
    if n == 0:
        break
    else:
        print()