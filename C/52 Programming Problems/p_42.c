#include <stdio.h>

int main()
{
    // Declare variables
    int i, j, t, n;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the number
        scanf("%d", &n);

        // Use loop to print the full expression
        for (j = n; j >= 0; j--) {
            if (j == 0) {
                printf("1\n"); // 2^0 = 1
                break;
            }
            if (j == 1) {
                printf("2 + "); // 2^1 = 2
            }
            else {
                printf("2^%d + ", j);
            }
        }
    }

    return 0;
}