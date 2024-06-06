#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int t, i, j;
    char str[10001];
    char ch;
    int len, count;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", str); // The space before %[^\n] is for whitespace character
        len = strlen(str); // Length of the string

        // Get the character that needs to be counted. Space for whitespace character
        scanf(" %c", &ch);

        count = 0; // Initialise count to 0

        // Use loop to go through every element of the string and check if given character is present there.
        // If present, increment the value of count by 1
        for (j = 0; j < len; j++) {
            if (str[j] == ch) {
                count++;
            }
        }

        // Print desired statement
        if (count > 0) {
            printf("Occurrence of '%c' in '%s' = %d\n", ch, str, count);
        }
        else {
            printf("'%c' is not present\n", ch);
        }
    }

    return 0;
}