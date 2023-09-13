#include <stdio.h>

// 1 <= a, b <= 100000. Hence, long long int
// Function for finding GCD
long long int GCD(long long int a, long long int b)
{
    // Declare variables
    long long int temp;

    // If the 2nd number is bigger than 1st number then swap them
    // a should alway be greater than b. or Euclidean Algorithm won't work
    if (b > a) {
        temp = a;
        a = b;
        b = temp;
    }

    // Euclidean Algorithm
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    // After applying Euclidean Algorithm, GCD = a. So, return a.
    return a;
}

int main()
{
    // Declare variables
    int i, t;
    long long int a, b, c, gcd, lcm, j;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);

        // Calculate GCD of A, B using GCD() function
        gcd = GCD(a, b);

        // Calculate LCM
        lcm = (a * b) / gcd;

        // Print multiples of LCM
        for (j = lcm; j <= c; j += lcm) {
            printf("%lld\n", j);
        }

        printf("\n");
    }

    return 0;
}

// Accepted at DimikOJ
// TLE at LightOJ