#include <stdio.h>

int main()
{
    // Declare variables
    int i, t;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Initialize array to track presence of numbers
        int ara[100001] = {0};
        int i, N, num, missing;

        // Scan the number of elements in the current test case
        scanf("%d", &N);

        // Read the N-1 elements and mark their presence in the array
        for (i = 0; i < N - 1; i++) {
            scanf("%d", &num);
            ara[num] = 1;
        }

        // Find the first missing positive integer in the range [1, N]
        for (i = 1; i <= N; i++) {
            if (ara[i] == 0) {
                missing = i;
                break;
            }
        }

        // Print the missing number
        printf("%d\n", i);
    }

    return 0;
}

// ChatGPT is better at commenting than me :D
// From now on. I'm gonna use ChatGPT to comment my codes :D