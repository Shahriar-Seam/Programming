#include <stdio.h>
#include <math.h>

// Use this function to check if a number is a perfect square
// I previously named this function is_prime. :|
void is_square(int n)
{
    double root;

    root = sqrt(n);  // sqrt(n) = Square Root of n

    // Floor(n) function outputs biggest integer <= n
    // floor(2.8) = 2, floor(2) = 2
    // Check if the number is equal to the square of the floor of the root of the number. -_- (Probably don't need this though)
    // But I like it :D
    if (pow(root, 2) == pow(floor(root), 2)) {
        printf("YES");
    }

    else {
        printf("NO");
    }
}

int main()
{
    // Declare variables
    int t, n, i;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 1; i <= t; i++) {
        // Scan the number
        scanf("%d", &n);

        // Use the function to check if the number is a square
        is_square(n);

        // Print newline
        printf("\n");
    }

    return 0;
}