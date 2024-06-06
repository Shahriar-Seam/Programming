#include <stdio.h>

// Learn modular arithmetic to properly understand this code

// Function for finding the value of p^q mod c
int find_mod(int base, int exponent, int mod)
{
    // Any number when divided by 1 returns 0 as remainder
    if (mod == 1) {
        return 0;
    }

    // Declare and initialize variable
    int result = 1;
    base = base % mod; // Makes sure base value is within 1 to mod - 1 without affecting final result

    // Find the mod value
    // Use the algorithm described in the book
    while (exponent > 0) {
        // If exponent is odd eg. 45^65 can be written as 45^44 x 45
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent / 2; // Half the exponent
        base = (base * base) % mod; // Square the base
    }

    return result;
}

int main()
{
    // Declare variables
    int i, t, p, q, c, result;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the numbers
        scanf("%d %d %d", &p, &q, &c);

        // Use the function to calculate p^q mod c
        result = find_mod(p, q, c);

        // Print result
        printf("Result = %d\n", result);
    }

    return 0;
}