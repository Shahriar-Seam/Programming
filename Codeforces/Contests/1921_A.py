import math as m

for i in range(1, int(input()) + 1):
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())
    x3, y3 = map(int, input().split())
    x4, y4 = map(int, input().split())
    
    d = int(min(m.sqrt(((x1 - x2) ** 2) + ((y1 - y2) ** 2)), m.sqrt(((x2 - x3) ** 2) + ((y2 - y3) ** 2)), m.sqrt(((x3 - x4) ** 2) + ((y3 - y4) ** 2)), m.sqrt(((x1 - x4) ** 2) + ((y1 - y4) ** 2))))
    
    print(d ** 2)