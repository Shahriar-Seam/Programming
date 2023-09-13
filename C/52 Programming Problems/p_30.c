#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int t;
    unsigned long long int n, sum, i, root; // For huge number. 2^32 to 2^64

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Scan the number
        scanf("%llu", &n);
        
        // Initialise sum to 1. As all numbers have 1 as a proper divisor
        sum = 1;
        root = sqrt(n);

        // Find divisors of n and add them with sum
        for (i = 2; i <= root; i++) {
            if (n % i == 0) {
                sum = sum + i + n / i;
                
            }
        }

        // Check and print if n is a perfect number
        if (sum == n) {
            printf("YES, %llu is a perfect number!\n", n);
        }
        else {
            printf("NO, %llu is not a perfect number!\n", n);
        }
    }

    return 0;
}