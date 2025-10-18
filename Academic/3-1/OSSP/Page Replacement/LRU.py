num_pages = int(input())
ref_string = list(map(int, input().split()))
num_frames = int(input())

memo = []
recent_usage = []

table = []
total_page_fails = 0

for page in ref_string:
    pf = 0
    
    if page in memo:
        recent_usage.remove(page)
        recent_usage.append(page)
    else:
        if len(memo) < num_frames:
            memo.append(page)
            recent_usage.append(page)
        else:
            lru_page = recent_usage.pop(0)
            index = memo.index(lru_page)
            memo[index] = page
            recent_usage.append(page)
        
        pf = 1
        
        total_page_fails += 1
        
    if pf:
        pf = "PF|"
    else:
        pf = "  |"

    table.append([str(page) + ' |'] + ["- |"] + [str(c) + " |" for c in memo] + ["- |" for _ in range(num_frames - len(memo))] + ["- |"] + [pf])

table.insert(0, ['|' for i in range(num_frames + 4)])

table.insert(0, ["Frame/Page"] + ["-" * 10] + [(str(i) + " " * (10 - len(str(i)))) for i in range(1, num_frames + 1)] + ["-" * 10] + ["Page Fail "])

table = [list(row) for row in zip(*table)]

print('-' * (len(''.join(table[0])) + len(table[0])))

for row in table:
    print(*row)
    
print('-' * (len(''.join(table[0])) + len(table[0])))

print("Total page fails =", total_page_fails);