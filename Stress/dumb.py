def solve() :
    n = int(input())
    lst = list(map(int, input().split()))

    pointer = len(lst) - 2
    cnt = 0
    
    # print(pointer)

    while(pointer >= 0) :
        
        if(lst[pointer] == 0 and pointer > 0) :
            print(-1)
            return
        while(lst[pointer + 1] <= lst[pointer]) :

            lst[pointer] = lst[pointer] // 2
            cnt += 1

            if(lst[pointer] == 0 and pointer > 0) :
                print(-1)
                return
                    
        # print("yo")

        pointer -= 1
    
    print(cnt)


t = int(input())

for _ in range(t) :
    solve()
