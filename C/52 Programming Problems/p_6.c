#include <stdio.h>

int main()
{
    // Declare variables
    int t, i, n, sum;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the number
        scanf("%d", &n);

        // Calculate the sum of first and last digit
        sum = (n / 10000) + (n % 10);  // 46544 / 10000 = 4 (First digit)

        // Print sum
        printf("Sum = %d\n", sum);
    }

    return 0;
}