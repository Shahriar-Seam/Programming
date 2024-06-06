#include <stdio.h>

int main()
{
    int n, num = 1, row, col;
    int start_row, start_col, end_row, end_col;

    scanf("%d", &n);

    int arr[n][n];
    start_row = start_col = 0;
    end_row = end_col = n - 1;

    while (start_row <= end_row && start_col <= end_col) {
        for (col = start_col; col <= end_col; col++) {
            arr[start_row][col] = num++;
        }
        start_row++;

        for (row = start_row; row <= end_row; row++) {
            arr[row][end_col] = num++;
        }
        end_col--;

        for (col = end_col; col >= start_col; col--) {
            arr[end_row][col] = num++;
        }
        end_row--;

        for (row = end_row; row >= start_row; row--) {
            arr[row][start_col] = num++;
        }
        start_col++;
    }

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            if (arr[row][col] == n * n) {
                printf("T ");
            }
            else {
                printf("%d ", arr[row][col]);
            }
        }

        printf("\n");
    }

    return 0;
}