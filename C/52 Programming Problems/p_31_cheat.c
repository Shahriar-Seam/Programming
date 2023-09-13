#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int T, n;

    // Scan number of test cases
    scanf("%d", &T);

    // Run loop for all test cases
    while (T--) {
        // Scan the number
        scanf("%d", &n);

        // Check if the number is bigger than any of the perfect numbers
        // If n is bigger than any of the perfect numbers then print the number
        if (n >= 6) {
            printf("6\n");
        }
        if (n >= 28) {
            printf("28\n");
        }
        if (n >= 496) {
            printf("496\n");
        }
        if (n >= 8128) {
            printf("8128\n");
        }
        if (n >= 33550336) {
            printf("33550336\n");
        }

        printf("\n");
    }

    return 0;
}