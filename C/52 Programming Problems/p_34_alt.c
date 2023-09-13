#include <stdio.h>

long long int LCM(long long int a, long long int b)
{
    long long int i, lcm, temp;

    if (b > a) {
        temp = a;
        a = b;
        b = temp;
    }

    lcm = a;

    while (1) {
        if (lcm % b == 0) {
            return lcm;
            break;
        }
        else {
            lcm += a;
        }
    }
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

        // Calculate LCM
        lcm = LCM(a, b);

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