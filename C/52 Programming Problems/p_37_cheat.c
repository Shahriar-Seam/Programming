// Shows wrong answer on both
#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int i, t;
    char num[121];

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Scan the integer as a string
        scanf("%s", num);

        // Reverse and print the string
        if (num[0] == '-' && num[1] != '0') {
            printf("-");
            for (i = strlen(num) - 1; i > 0; i--) {
                printf("%c", num[i]);
            }
        }
        else if (num[0] == '-' && num[1] == '0') {
            printf("0");
        }
        else {
            for (i = strlen(num) - 1; i >= 0; i--) {
                printf("%c", num[i]);
            }
        }
        
        printf("\n");
    }

    return 0;
}