#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int i, j, t, x, k;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the numbers
        scanf("%d %d", &x, &k);

        // Initialise sum and power to 1
        int sum = 1, power = 1;

        // Use loop to find sum
        for (j = 1; j <= k; j++) {
            power = power * x;
            sum += power;
        }

        // Print result
        printf("Result = %d\n", sum);
    }

    return 0;
}