#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int i, j, t, len;
    char str[1002], rev_str[1002];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Get the string
        scanf("%s", str);

        // Length of the string
        len = strlen(str);

        // Reverse the string
        for (i = 0, j = len - 1; i < len; i++, j--) {
            rev_str[i] = str[j];
        }
        rev_str[i] = '\0';

        // Compare the strings and print if it is palindrome or not
        if (0 == strcmp(str, rev_str)) {
            printf("Yes! It is palindrome!\n");
        }
        else {
            printf("Sorry! It is not palindrome!\n");
        }
    }

    return 0;
}