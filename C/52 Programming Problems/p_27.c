#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int i, t, n, a, b, c, sum;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the number
        scanf("%d", &n);

        // Assign digits of the number to a, b, c
        a = n % 10;
        b = (n / 10) % 10;
        c = (n / 100);

        sum = pow(a, 3) + pow(b, 3) + pow(c, 3);

        // Check if sum is equal to original number.
        if (sum == n) {
            printf("%d is an armstrong number!\n", n);
        }
        else {
            printf("%d is not an armstrong number!\n", n);
        }
    }

    return 0;
}