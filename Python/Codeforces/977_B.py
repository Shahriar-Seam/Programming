n = int(input())
str = input()

s_list = []

for i in range(0, len(str)):
    s = str[i : i + 2]
    
    if (len(s) == 2):
        s_list.append(s)
        
s_set = set(s_list)
max_cnt = 0
max_s = ""

for i in s_set:
    cnt = s_list.count(i)
    
    if (cnt > max_cnt):
        max_cnt = cnt
        max_s = i
                
print(max_s)