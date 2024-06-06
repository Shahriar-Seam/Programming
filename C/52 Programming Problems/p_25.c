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
    long long int lcm, a, b, gcd;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the numbers
        scanf("%lld %lld", &a, &b);

        // Use GCD function to find GCD
        gcd = GCD(a, b);

        // Calculate LCM
        // a * b = GCD * LCM
        // => LCM = (a * b) / GCD
        lcm = (a * b) / gcd;

        // Print LCM
        printf("LCM = %lld\n", lcm);
    }

    return 0;
}