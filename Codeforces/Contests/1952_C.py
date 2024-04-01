def count_surrounding_ones(grid, row, col):
    count = 0
    for i in range(row - 1, row + 2):
        for j in range(col - 1, col + 2):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]):
                count += int(grid[i][j])
    return count

def count_odd_cells(grid):
    odd_count = 0
    for i in range(1, len(grid) - 1):
        for j in range(1, len(grid[0]) - 1):
            if count_surrounding_ones(grid, i, j) % 2 == 1:
                odd_count += 1
    return odd_count

# Read input
grid = [input() for _ in range(21)]

# Count odd cells
result = count_odd_cells(grid)
print(result)
