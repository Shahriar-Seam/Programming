import calendar

year = int(input())
rows = 0

for m in range(1, 13):
    rows += len(calendar.month(year, m).split("\n")) - 3
    
print(rows)