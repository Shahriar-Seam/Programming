#include <stdio.h>

int main()
{
    // Declare variables
    int t, i, j, k, n;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the size
        scanf("%d", &n);

        // Run the outer loop for rows
        for (j = 0; j < n; j++) {
            // The inner loop will fill elements of the rows
            for (k = 0; k < n; k++) {
                printf("*");
            }

            // Print newline after every row
            printf("\n");
        }

        // Print newline after every square
        printf("\n");

        // Comment the upper print command and uncomment the lower for LightOJ. The following Doesn't print extra newline after last square
        // if (i != t - 1) {
        // 	printf("\n");
        // }
    }

    return 0;
}