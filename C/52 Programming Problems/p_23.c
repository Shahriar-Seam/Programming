#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    char str[101];
    int i, j, t;

    // Scan number of test cases
    scanf("%d", &t);
    
    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", str); // The space before %[^\n] is for whitespace character

        // Learn about ASCII table
        // 'A' = 65. Hence to print 1 for A we need to deduct 64 from its ASCII value
        // Same for other letters
        // So, go through the whole string, deduct 64 from its ASCII value and print
        for (j = 0; j < strlen(str); j++) {
            printf("%d", str[j] - 64);
        }

        printf("\n");
    }

    return 0;
}