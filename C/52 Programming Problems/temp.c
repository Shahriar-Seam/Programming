// This is for testing purposes
#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int i, j, t;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        char str[1005];
        int count[256] = {0}; // Using 256 for ASCII characters (extend as needed)
        int len;

        // Scan the input string for the current test case
        scanf(" %[^\n]", str);

        // Calculate the length of the input string
        len = strlen(str);

        // Count the frequency of each character
        for (i = 0; i < len; i++) {
            count[(int)str[i]]++;
        }

        for (i = 0; i < 256; i++) {
            if (count[i] != 0) printf("%d ", count[i]);
        }

        // Print the frequency of each character for the current test case
        for (i = 0; i < len; i++) {
            if (count[(int)str[i]] != 0) {
                printf("%c: %d\n", str[i], count[(int)str[i]]);
                count[(int)str[i]] = 0; // Reset the count to avoid double counting
            }
        }
    }

    return 0;
}
