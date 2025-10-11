num_pages = int(input())
ref_string = input()
num_frames = int(input())

memo = [' '] * num_frames
reference = [0] * (num_pages + 1)
pointer = 0
ref_mod = []

table = []
total_page_fails = 0

for page in ref_string:
    pf = 0
    
    if page not in memo:
        pf = 1
        total_page_fails += 1
        
        if memo[pointer] == ' ':
            memo[pointer] = page
            
            pointer += 1
            
            pointer %= num_frames
        else:
            pointer = 0
            
            while True:
                if reference[int(memo[pointer % num_frames])]:
                    reference[int(memo[pointer % num_frames])] = 0
                else:
                    break
                
                pointer += 1
        
            j = 0
            
            while j < pointer % num_frames:
                temp = memo.pop(0)
                memo.append(temp)
                
                reference[int(temp)] = 0
                
                j += 1
                
            memo.pop(0)
            memo.append(page)
    else:
        reference[int(page)] = 1
        
    if pf:
        pf = "PF|"
    else:
        pf = "  |"

    table.append([page + ' |'] + ["- |"] + [c + " |" for c in memo] + ["- |"] + [pf])
    
    ref.append(reference.copy())

table.insert(0, ['|' for i in range(num_frames + 4)])

table.insert(0, ["Frame/Page"] + ["-" * 10] + [(str(i) + " " * (10 - len(str(i)))) for i in range(1, num_frames + 1)] + ["-" * 10] + ["Page Fail "])

table = [list(row) for row in zip(*table)]

print('-' * (len(''.join(table[0])) + len(table[0])))

for row in table:
    print(*row)
    
print('-' * (len(''.join(table[0])) + len(table[0])))

ref = [list(row) for row in zip(*ref)]

print()
print("Reference Bits:")

print('-' * (len(''.join(table[0])) + len(table[0])))

for i in range(0, num_pages + 1):
    print(i, ' ' * 8, '|', end=' ');
    
    for j in ref[i]:
        print(j, '|', end=' ')
    
    print()
    
print('-' * (len(''.join(table[0])) + len(table[0])))

print("Total page fails =", total_page_fails)