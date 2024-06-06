#include <stdio.h>

int main()
{
    // Declare variables
    int i, t, n, max, count;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Take input
        scanf("%d %d", &n, &max);

        // Check if invalid
        if (n > max) {
            printf("Invalid!\n");
        }

        else {
            // Print multiples of n from n to max (both inclusive)
            for (i = n; i <= max; i += n) {
                printf("%d\n", i);
            }
        }

        // Separator
        printf("\n");
    }

    return 0;
}