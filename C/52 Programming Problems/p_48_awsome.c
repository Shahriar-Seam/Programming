#include <stdio.h>

int main()
{
    // Declare variables
    int i, t;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Declare variables for the current test case
        long long int n, num, sum1, sum2 = 0, missing;

        // Scan the number of elements in the current test case using long long int
        scanf ("%lld", &n);

        // Calculate the sum of all integers from 1 to n (inclusive)
        sum1 = n * (n + 1) / 2;

        // Read the n-1 elements and calculate their sum using long long int
        for (i = 0; i < n - 1; i++) {
            scanf("%lld", &num);
            sum2 += num;
        }

        // Calculate the missing number by finding the difference between the expected sum and the actual sum
        missing = sum1 - sum2;

        // Print the missing number using long long int format specifier
        printf("%lld\n", missing);
    }

    return 0;
}
