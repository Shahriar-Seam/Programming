for s in[*open(0)][2::2]:print(max(max(map(len,s.split(max(s))))for
s in map(''.join,zip(*(f'{int(x):20b}'for x in s.split()))))+1)