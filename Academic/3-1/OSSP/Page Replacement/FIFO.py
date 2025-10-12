num_pages = int(input())
ref_string = input()
num_frames = int(input())

memo = [' '] * num_frames
index = 0

table = []
total_page_fails = 0

for page in ref_string:
    pf = 0
    
    if page not in memo:
        memo[index] = page

        index += 1

        index %= num_frames
        
        pf = 1
        
        total_page_fails += 1
        
    if pf:
        pf = "PF|"
    else:
        pf = "  |"

    table.append([page + ' |'] + ["- |"] + [c + " |" for c in memo] + ["- |"] + [pf])

table.insert(0, ['|' for i in range(num_frames + 4)])

table.insert(0, ["Frame/Page"] + ["-" * 10] + [(str(i) + " " * (10 - len(str(i)))) for i in range(1, num_frames + 1)] + ["-" * 10] + ["Page Fail "])

table = [list(row) for row in zip(*table)]

print('-' * (len(''.join(table[0])) + len(table[0])))

for row in table:
    print(*row)
    
print('-' * (len(''.join(table[0])) + len(table[0])))

print("Total page fails =", total_page_fails);