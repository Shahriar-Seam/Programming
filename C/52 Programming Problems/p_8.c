#include <stdio.h>

// Function to sort and print 3 numbers in ascending order
void sort(int a, int b, int c)
{
    if (a < b && a < c) {
        if (b < c) {
            printf(" %d %d %d", a, b, c);
        }
        else {
            printf(" %d %d %d", a, c, b);
        }
    }
    if (b < a && b < c) {
        if (a < c) {
            printf(" %d %d %d", b, a, c);
        }
        else {
            printf(" %d %d %d", b, c, a);
        }
    }
    if (c < a && c < b) {
        if (a < b) {
            printf(" %d %d %d", c, a, b);
        }
        else {
            printf(" %d %d %d", c, b, a);
        }
    }
}

int main()
{
    // Declare variables
    int t, i, a, b, c;
    
    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 1; i <= t; i++) {
        // Scan given numbers
        scanf("%d %d %d", &a, &b, &c);

        // Print case no.
        printf("Case %d:", i);

        // Use the function to sort and print the numbers
        sort(a, b, c);

        // Print newline
        printf("\n");
    }

    return 0;
}
