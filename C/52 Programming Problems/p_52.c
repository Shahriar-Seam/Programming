#include <stdio.h>
#include <string.h>

// Function to count occurrences of str2 in str1
void count(char str1[], char str2[])
{
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int i, j, count = 0;

    // Loop through str1 to find occurrences of str2
    for (i = 0; i <= (str1_len - str2_len); i++) {
        // Check if the first character of str2 matches the character at index i in str1
        if (str2[0] == str1[i]) {
            // If the first character matches, check the rest of the characters
            for (j = 1; j < str2_len; j++) {
                // If any character does not match, break out of the loop
                if (str2[j] != str1[i + j]) {
                    break;
                }
            }

            // If all characters match, increment the count of occurrences
            if (j == str2_len) {
                count++;
            }
        }
    }

    // Print the total count of occurrences of str2 in str1
    printf("%d\n", count);
}

int main()
{
    // Declare variables
    int t;
    char str1[130], str2[130];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Read two strings (str1 and str2) for each test case
        scanf("%s", str1);
        scanf("%s", str2);

        // Call the count function to find occurrences of str2 in str1
        count(str1, str2);
    }

    return 0;
}
