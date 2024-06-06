#include <stdio.h>

long long int factorial(long long int n)
{
    // Declare variables
    int i;
    long long int fact = 1;

    // Calculate factorial(n)
    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

int main()
{
    // Declare variables
    int i, t;
    long long int n, j;
    double sum;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the number
        scanf("%lld", &n);

        // Initialise sum to 0
        sum = 0;

        // Use loop to calculate sum
        for (j = 1; j <= n; j++) {
            sum += ((double) j / factorial(j));
        }

        // Print sum
        printf("%0.4lf\n", sum);
    }

    return 0;
}