#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int t, i, j, n, count;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the number
        scanf("%d", &n);
        
        // Initialise count to 0
        count = 0;
        // legendre's formula
        // As the max number can be 100 hence the program will check up to 5^3. 5^3 = 125.
        for (j = 1; j <= 3; j++) {
            count += n / pow(5, j);
        }

        // Print number of 5 as factor in the factorial resulting in trailing zeros.
        printf("%d\n", count);
    }

    return 0;
}