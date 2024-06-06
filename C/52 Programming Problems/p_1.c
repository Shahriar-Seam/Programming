#include <stdio.h>

int main()
{
    // Declare variables
    int t, i, n;

    // Scan the number of test cases
    scanf("%d", &t);

    // Run the loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the input
        scanf("%d", &n);

        // Check if the number is even or odd and print it
        if (n % 2 == 0) {
            printf("even\n");
        }
        else {
            printf("odd\n");
        }
    }

    return 0;
}