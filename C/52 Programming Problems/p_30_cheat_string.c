#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    int i, t, j;
    char perfect_numbers[8][100] = {
        "6", "28", "496", "8128", "33550336", "8589869056", "137438691328", "2305843008139952128"
    };  // Perfect numbers which are less than 2^64
    char num[100];
    int present;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan a number as string
        scanf("%s", num);

        num[strlen(num)] = '\0'; // Indicate end of string

        present = 0; // Let's assume the number isn't present

        // Check if the given number is in the array
        // If the number is present then change value of present to 1 and break the loop
        for (j = 0; j < 8; j++) {
            // Use strcmp() function to compare the numbers (here, as strings)
            if (0 == strcmp(perfect_numbers[j], num)) {
                present = 1;
                break;
            }
        }

        // Print if the number is a perfect number or not
        if (present) {
            printf("YES, %s is a perfect number!\n", num);
        }
        else {
            printf("NO, %s is not a perfect number!\n", num);
        }
    }

    return 0;
}

// Finally, after 7+ hours. It works. Yippee... :D
// I can sleep peacefully now...