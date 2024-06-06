#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int i, len, t, j;
    char str[10001];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (j = 0; j < t; j++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", str); // The space before %[^\n] is for whitespace character

        // Initialise array of count to 0
        int count[26] = {0};
        len = strlen(str); // Length of the string

        // Loop to increment value of count at respective positions
        for (i = 0; i < len; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                count[str[i] - 'a']++;
            }
        }

        // Print letter and count
        for (i = 0; i < 26; i++) {
            if (count[i] != 0) {
                printf("%c = %d\n", 'a' + i, count[i]);
            }
        }

        printf("\n");
    }

    return 0;
}

// Doesn't work on LightOJ
// Check p_15_alt for LightOJ