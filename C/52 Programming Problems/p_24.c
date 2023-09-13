#include <stdio.h>

int main()
{
    // Declare and initialize variables
    int arr[101] = {0};
    int t, i, j, len;

    // Take number of test cases
    scanf("%d", &t);

    // Loop for all test cases
    for (i = 0; i < t; i++) {
        // Take the first element which shows the size of the array
        scanf("%d", &len);

        // Fill up the array of size "len" with the rest of the elements
        for (j = 0; j < len ; j++) {
            scanf("%d", &arr[j]);
        }

        // Print the alternate numbers
        for (j = 0; j < len; j += 2) {
            printf("%d", arr[j]);

            // Don't print space after last element. (This is for DimikOJ. LightOJ works with just printf("%d "))
            if (j == len - 1 || j == len - 2) {
                continue;
            }
            else {
                printf(" ");
            }
        }

        // Print newline after each output line
        printf("\n");
    }

    return 0;
}