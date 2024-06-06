#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int t, i, j, len;
    char str[1001];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", str); // The space before %[^\n] is for whitespace character

        len = strlen(str); // Calculate the length of the string

        // Print the string from highest to lowest index
        // This will print the string reversely
        for (j = len - 1; j >= 0; j--) {
            printf("%c", str[j]);
        }

        printf("\n");
    }

    return 0;
}