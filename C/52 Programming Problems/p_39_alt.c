#include <stdio.h>
#include <string.h>

// Function for checking if a string is palindrome or not
int is_palindrome(char str[])
{
    // Declare variables
    // Let's assume the string is palindrome
    int i, palindrome = 1, len;

    // Length of the string
    len = strlen(str);

    // The string needs to be checked upto half of it
    // If first half is not equal to second half then it is not palindrome
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            palindrome = 0;
            break;
        }
    }

    return palindrome;
}

int main()
{
    // Declare variables
    int i, t;
    char str[1002];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the string
        scanf("%s", str);

        // Check and print if the string is palindrome
        if (is_palindrome(str) == 1) {
            printf("Yes! It is palindrome!\n");
        }
        else {
            printf("Sorry! It is not palindrome!\n");
        }
    }

    return 0;
}