#include <stdio.h>

int main()
{
    // Declare variables
    int t, i, n, j;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 1; i <= t; i++) {
        // Scan the number
        scanf("%d", &n);

        // Print case number
        printf("Case %d:", i);
        // Find the divisors of the number and print them
        for (j = 1; j <= n; j++) {
            if (n % j == 0) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }

    return 0;
}