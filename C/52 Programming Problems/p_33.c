#include <stdio.h>

int main()
{
    // Declare variables
    long long int i, t, min, max, n, j;

    // Scan number of test cases
    scanf("%lld", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Take input
        scanf("%lld %lld %lld", &min, &max, &n);

        // Find the numbers which are divisible by n in the given range
        for (j = min; j <= max; ) {
            // Check if the min_value is divisible
            if (j % n == 0) {
                printf("%lld\n", j);
                j += n;
            }
            // If not change value to lowest divisible integer greater than min_value
            else {
                j = min + (n - (min % n));
            }
        }

        // Separator
        printf("\n");
    }

    return 0;
}