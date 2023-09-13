#include <stdio.h>

int main()
{
    // Declare variables
    int i, t;
    long long int j, perfect;
    long long int perfect_numbers[8] = {
        6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128
    };
    long long int n;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        scanf("%lld", &n);

        perfect = 0;

        if (n >= 0) {
            for (j = 0; j < 8; j++) {
                if (n == perfect_numbers[j]) {
                    perfect = 1;
                    break;
                }
            }

            if (perfect == 1) {
                printf("YES, %lld is a perfect number!", n);
            }
            else {
                printf("NO, %lld is not a perfect number!", n);
            }

            if (i != t - 1) {
                printf("\n");
            }
        }
        else {
            printf("NO, %lld is not a perfect number!", n);
        }
    }

    return 0;
}