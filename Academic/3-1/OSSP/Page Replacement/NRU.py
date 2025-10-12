num_pages = int(input())
ref_string = input()
mod_bits = input()
num_frames = int(input())

memo = [' '] * num_frames
reference = [0] * (num_pages + 1)
modification = [0] * (num_pages + 1)
table = []
total_page_fails = 0
pointer = 0
reset_interval = num_frames

for i in range(len(ref_string)):
    page = ref_string[i]
    pf = 0
    pointer += 1
    mod_bit = int(mod_bits[i])
    page_int = int(page)

    if page in memo:
        index = memo.index(page)
        reference[page_int] = 1
        modification[page_int] = mod_bit
    else:
        pf = 1
        total_page_fails += 1

        if ' ' in memo:
            index = memo.index(' ')
            memo[index] = page
            reference[page_int] = 1
            modification[page_int] = mod_bit
        else:
            classes = {0: [], 1: [], 2: [], 3: []}

            for j in range(num_frames):
                frame_page = memo[j]
                frame_page_int = int(frame_page)
                cls = (reference[frame_page_int] << 1) | modification[frame_page_int]
                classes[cls].append(j)

            for cls in range(4):
                if classes[cls]:
                    victim = classes[cls][0]
                    break

            memo[victim] = page
            reference[page_int] = 1
            modification[page_int] = mod_bit

    if pointer % reset_interval == 0:
        reference = [0] * (num_pages + 1)

    if pf:
        pf_str = "PF|"
    else:
        pf_str = "  |"
        
    print("Frames:\t\t\t  ", memo)
    print("Reference Bits:   ", reference)
    print("Modification Bits:", modification)
    
    print()

    table.append([page + ' |'] + ["- |"] + [c + " |" for c in memo] + ["- |"] + [pf_str])

table.insert(0, ['|' for _ in range(num_frames + 4)])
table.insert(0, ["Frame/Page"] + ["-" * 10] + [(str(i) + " " * (10 - len(str(i)))) for i in range(1, num_frames + 1)] + ["-" * 10] + ["Page Fail "])
table = [list(row) for row in zip(*table)]

print('-' * (len(''.join(table[0])) + len(table[0])))
for row in table:
    print(*row)
print('-' * (len(''.join(table[0])) + len(table[0])))

print(f"\nTotal Page Faults: {total_page_fails}")
