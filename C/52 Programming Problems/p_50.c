#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int l, r, t, len;  // 'l' and 'r' are loop counters, 't' is the number of test cases, 'len' stores the length of the string.
    char str[51];      // 'str' is an array to store the input string (up to 50 characters + 1 for null-terminator).

    // Scan number of test cases
    scanf("%d", &t);   // Read the number of test cases from the user.

    // Run loop for all test cases
    while (t--) {      // Loop through each test case until 't' becomes zero.

        // Read the input string for the current test case
        scanf("%s", str); // Note: This may not be safe for strings longer than 50 characters.

        len = strlen(str); // Calculate the length of the input string.

        // Loop for 'L' Operations
        for (l = 0; l < len; l++) { // Iterate through each character in the string.

            if (str[l] == 'L') {    // If the current character is 'L':
                str[l] = str[l - 1]; // Replace 'L' with the character just before it in the string.
            }
        }

        // Loop for 'R' Operations
        for (r = 0; r < len; r++) { // Iterate through each character in the string.

            if (str[r] == 'R') {    // If the current character is 'R':
                str[r] = str[r + 1]; // Replace 'R' with the character just after it in the string.
            }
        }

        // Print the modified string for the current test case
        printf("%s\n", str); // Output the modified string for this test case.
    }

    return 0; // Exit the program with a successful status.
}
