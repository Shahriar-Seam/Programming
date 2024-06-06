#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int t, i, j, count;
    char str[10002];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", str); // The space before %[^\n] is for whitespace character

        // Initialise count to 1. (I think 0 would be more appropriate. But this one feels better actually.)
        count = 1;

        // Go through the string and find space. If found, increment value of count by 1
        for (j = 0; j < strlen(str); j++) {
            if (str[j] == ' ') {
                count++;
            }
        }

        // Print number of spaces + 1. (This is why I initialised count to 1. So, the program doesn't have to add 1.)
        printf("Count = %d\n", count);
    }

    return 0;
}