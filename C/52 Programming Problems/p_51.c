#include <stdio.h>
#include <string.h>

// Function to search for the occurrence of one string (str2) within another (str1)
void search(char str1[], char str2[])
{
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int i, j;

    // Loop through str1 to find occurrences of the first character of str2
    for (i = 0; i <= (str1_len - str2_len); i++) {
        // Check if the first character of str2 is found in str1
        if (str2[0] == str1[i]) {
            // If the first character is found, enter a nested loop to check the subsequent characters
            for (j = 1; j < str2_len; j++) {
                // Check if the subsequent characters of str2 match corresponding characters in str1
                if (str2[j] != str1[i + j]) {
                    // If any character doesn't match, break out of the nested loop
                    break;
                }
            }
            // If j == str2_len, it means all characters of str2 matched the corresponding characters in str1
            if (j == str2_len) {
                // Print the starting index of the occurrence of str2 in str1
                printf("%d\n", i);
                // Break out of the outer loop, as we only need to find the first occurrence
                break;
            }
        }
    }
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
        // Scan two strings, str1 and str2, for each test case
        scanf("%s", str1);
        scanf("%s", str2);

        // Call the search function to find and print the occurrence of str2 in str1
        search(str1, str2);
    }

    return 0;
}
