s = input()
n = len(s)
final_sum = 0

for mask in range((1 << (n - 1))):
    s_list = list(s)
    pos = 1

    for i in range(n):
        if mask & (1 << i):
            s_list.insert(pos, '+')
            pos += 1
        
        pos += 1
    
    s_temp = "".join(s_list)

    final_sum += eval(s_temp)

print(final_sum)