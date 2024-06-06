#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int t, i, j, count;
    char str[1002];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", str); // The space before %[^\n] is for whitespace character
        count = 0; // Initialise count to 0

        // Check the whole string and if vowel is found, increment the value of count by 1
        for (j = 0; j < strlen(str); j++) {
            if ((str[j] == 'a') || (str[j] == 'e') || (str[j] == 'i') || (str[j] == 'o') || (str[j] == 'u')) {
                count++;
            }
        }

        // Print number of vowels
        printf("Number of vowels = %d\n", count);
    }

    return 0;
}