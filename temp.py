def read_and_rotate_matrix():
    # Read 8x8 matrix
    matrix = []
    for _ in range(8):
        row = input().strip()
        matrix.append(list(row))
    
    # Rotate 90 degrees counterclockwise
    rotated = [[matrix[j][7-i] for j in range(8)] for i in range(8)]
    
    # Print rotated matrix
    for row in rotated:
        print(''.join(row))

# Read and rotate the matrix
read_and_rotate_matrix()