#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int i, j, t, x, k, result;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the numbers
        scanf("%d %d", &x, &k);

        // Initialise result to 0
        result = 0;

        // Use loop to add all the expressions
        for (j = 0; j <= k; j++) {
            result += pow(x, j);
        }

        // Print result
        printf("Result = %d\n", result);
    }

    return 0;
}