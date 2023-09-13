#include <stdio.h>
#include <string.h>

// Function to print a string reversed
void print_reverse(char str[])
{
    int i;

    // Print the string from highest to lowest index. Which prints reversed string.
    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

int main()
{
    // Declare variables
    int i, t, j, k;
    char S[1002], word[1002];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the string with until enter is pressed
        scanf(" %[^\n]", S); // The space before %[^\n] is for whitespace character

        // Isolate the words
        for (j = 0, k = 0; j < strlen(S); j++) {
            if (S[j] != ' ') {
                word[k] = S[j]; // Copy non-space elements from the string to word
                k++; // Index
            }

            else if (k > 0) {
                word[k] = '\0'; // Indicate end of word
                print_reverse(word); // Prints reversed word
                printf(" "); // Separates words
                k = 0;
            }
        }

        // At the above loop the last word won't print. Because the loop breaks before entering else if block as j < strlen(S) becomes false already
        // Hence, the last word is printed outside of the loop, here.
        if (k > 0) {
            word[k] = '\0';
            print_reverse(word);
            printf("\n");
        }
    }

    return 0;
}