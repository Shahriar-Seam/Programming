#include <stdio.h>

int main()
{
    // Declare variables
    int i, t;
    char ch;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the character
        scanf(" %c", &ch);

        // Check the character
        if (ch >= 'A' && ch <= 'Z') {
            printf("Uppercase Character\n");
        }
        else if (ch >= 'a' && ch <= 'z') {
            printf("Lowercase Character\n");
        }
        else if (ch >= '0' && ch <= '9') {
            printf("Numerical Digit\n");
        }
        else {
            printf("Special Characters\n"); // -_-
        }
    }

    return 0;
}