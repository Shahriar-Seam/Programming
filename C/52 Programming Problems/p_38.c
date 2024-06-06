#include <stdio.h>

int main()
{
    // Declare variables
    int i, t, n, m, j;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Scan the numbers
        scanf("%d %d", &n, &m);

        // Print the upper part
        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++) {
                printf("%d", m);
                if (j != i - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Print the lower part
        for (i = n; i > 0; i--) {
            for (j = 0; j < i; j++) {
                printf("%d", m);
                if (j != i - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Separator
        printf("\n");
    }

    return 0;
}