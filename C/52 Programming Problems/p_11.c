#include <stdio.h>

int main()
{
    // Declare variables
    int t, n, i, j;
    long long int fact; // int can support up to 12!. long long int can support up to 20!

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 1; i <= t; i++) {
        // Scan the number
        scanf("%d", &n);

        fact = 1; // Initialise factorial to 1

        if (n == 0) {
            printf("%d\n", 1); // 0! = 1
        }
        else if (n > 0) {
            for (j = 2; j <= n; j++) {  // Doraemon * 1 != Nobita. So, I started from 2. (Also it probably uses less memory.)
                fact *= j;  // factorial of n = 1 * 2 * 3 * 4 * 5 * ... * (n - 1) * n
            }

            printf("%lld\n", fact);  // %lld for long long int
        }
    }

    return 0;
}