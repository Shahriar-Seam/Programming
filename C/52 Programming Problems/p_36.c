#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int i, j, t, n;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Scan the number of words
        scanf("%d", &n);

        // Declare string of intended size
        char str[n][10002];
        char temp[10002];

        // Get the words
        for (i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }

        // Sort the words
        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                if (strcmp(str[i], str[j]) > 0) {
                    strcpy(temp, str[i]);
                    strcpy(str[i], str[j]);
                    strcpy(str[j], temp);
                }
            }
        }

        // Print the words in order
        printf("\n"); // Comment this line on LightOJ
        for (i = 0; i < n; i++) {
            printf("%s\n", str[i]);
        }
    }

    return 0;
}