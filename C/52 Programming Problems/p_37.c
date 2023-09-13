#include <stdio.h>

int main()
{
    // Declare variables
    int i, t, num, rev;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the number
        scanf("%d", &num);

        // Initialise reversed number to 0
        rev = 0;

        // Reverse the number and save it to rev
        while (num != 0) {
            rev = rev * 10;
            rev += num % 10;
            num /= 10;
        }

        // Print reversed number
        printf("%d\n", rev);
    }

    return 0;
}