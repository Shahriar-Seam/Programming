#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int t, i;
    char n[101];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the number as a string
        scanf("%s", n);

        // Find index of the last digit
        int last_dgt_indx = strlen(n) - 1;

        // Check if the last digit is even or odd and print it
        if ((n[last_dgt_indx] - '0') % 2 == 0) {
            printf("even\n");
        }
        else {
            printf("odd\n");
        }
    }

    return 0;
}