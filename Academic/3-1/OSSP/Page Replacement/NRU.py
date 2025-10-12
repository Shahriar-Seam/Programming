num_pages = int(input("Number of pages:\n"))
ref_string = list(map(int, input("Reference string:\n").split()))
num_frames = int(input("Number of frames:\n"))

memo = [' '] * num_frames
reference = [0] * num_frames
modification = [0] * num_frames
ref_mod = []
table = []
total_page_fails = 0
pointer = 0
reset_interval = num_frames

for i in range(len(ref_string)):
    page = ref_string[i]
    pf = 0
    pointer += 1
    page_int = int(page)
    
    if ' ' in memo:
        memo[memo.index(' ')] = page
    else:
        ref_mod = list(map(str, input("ref mod:\n").split()))
        
        reference = [int(c[0]) for c in ref_mod]
        modification = [int(c[1]) for c in ref_mod]
        
    if page in memo:
        index = memo.index(page)
    else:
        pf = 1
        total_page_fails += 1
        
        classes = {0: [], 1: [], 2: [], 3: []}

        for j in range(num_frames):
            frame_page = memo[j]
            cls = (reference[j] << 1) | modification[j]
            classes[cls].append(j)

        for cls in range(4):
            if classes[cls]:
                victim = classes[cls][0]
                break

        memo[victim] = page

    if pf:
        pf_str = "PF|"
    else:
        pf_str = "  |"
        
    print("Frames:\t\t\t  ", memo)
    print("Reference Bits:   ", reference)
    print("Modification Bits:", modification)
    
    print()

    table.append([str(page) + ' |'] + ["- |"] + [str(c) + " |" for c in memo] + ["- |"] + [pf_str])

table.insert(0, ['|' for _ in range(num_frames + 4)])
table.insert(0, ["Frame/Page"] + ["-" * 10] + [(str(i) + " " * (10 - len(str(i)))) for i in range(1, num_frames + 1)] + ["-" * 10] + ["Page Fail "])
table = [list(row) for row in zip(*table)]

print('-' * (len(''.join(table[0])) + len(table[0])))
for row in table:
    print(*row)
print('-' * (len(''.join(table[0])) + len(table[0])))

print(f"\nTotal Page Faults: {total_page_fails}")
