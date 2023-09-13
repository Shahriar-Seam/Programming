#include <stdio.h>

// Declare global variable
#define size 51
long long int pascals_triangle[size][size];

// Function to fill Pascal's triangle
void fill_pascals_triangle()
{
    // Declare variable
    long long int i, j;

    // Elements of first 2 row
    pascals_triangle[0][0] = 1;
    pascals_triangle[1][0] = 1;
    pascals_triangle[1][1] = 1;

    // Fill other elements
    for (i = 2; i < size; i++) {
        pascals_triangle[i][0] = 1; // 1st element of every row is 1

        for (j = 1; j < i; j++) {
            pascals_triangle[i][j] = pascals_triangle[i - 1][j - 1] + pascals_triangle[i - 1][j];
        }

        pascals_triangle[i][i] = 1; // Last element of every row is 1
    }
}

int main()
{
    // Declare variables
    int i, t, n;
    fill_pascals_triangle();

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Scan the number
        scanf("%d", &n);

        // Print it
        for (i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                printf("%lld", pascals_triangle[i][j]);
                if (j != i) {
                    printf(" "); // No extra space for DimikOJ
                }
            }

            printf("\n");
        }

        // Separator
        printf("\n");
    }

    return 0;
}