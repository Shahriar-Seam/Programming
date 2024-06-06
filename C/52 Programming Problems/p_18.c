#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int t, i, j, k, m;
    char str[10001];
    char vowel[10001], consonant[10001];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", str); // The space before %[^\n] is for whitespace character

        // Initialize indexes k and m to 0
        k = 0;
        m = 0;

        // Check the whole string
        for (j = 0; j < strlen(str); j++) {
            // If vowel is found, put it to array named vowel
            if ((str[j] == 'a') || (str[j] == 'e') || (str[j] == 'i') || (str[j] == 'o') || (str[j] == 'u')) {
                vowel[k] = str[j];
                k++;
            }
            // Else, put non-vowels to array names consonants
            else {
                consonant[m] = str[j];
                m++;
            }
        }
        // Insert NULL character to indicate end of string
        vowel[k] = '\0';
        consonant[m] = '\0';

        // Print non-space characters in the arrays
        // Vowels
        for (k = 0; k < strlen(vowel); k++) {
            if (vowel[k] != ' ') {
                printf("%c", vowel[k]);
            }
        }
        // Newline for separation
        printf("\n");
        // Consonant
        for (m = 0; m < strlen(consonant); m++) {
            if (consonant[m] != ' ') {
                printf("%c", consonant[m]);
            }
        }
        printf("\n");
    }

    return 0;
}