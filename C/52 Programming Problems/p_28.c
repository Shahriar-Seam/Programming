#include <stdio.h>

int main()
{
    // Declare variables
    int i, j, t, n, num[25] = {0}, sorted;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan array size
        scanf("%d", &n);
        // Scan the array
        for (j = 0; j < n; j++) {
            scanf("%d", &num[j]);
        }

        // Let's assume the array is sorted
        sorted = 1;
        // Check order of the array
        if (num[0] > num[n - 1]) {
            // Check if the array is sorted
            for (j = 0; j < n - 1; j++) {
                if (num[j] < num[j + 1]) {
                    sorted = 0;
                    break;
                }
            }
        }
        else {
            // Check if the array is sorted
            for (j = 0; j < n - 1; j++) {
                if (num[j] > num[j + 1]) {
                    sorted = 0;
                    break;
                }
            }
        }

        // Print
        if (sorted) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}