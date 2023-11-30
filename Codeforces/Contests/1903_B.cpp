#include <stdio.h>

void findArray(int n, int matrix[100][100]) {
    int a[n]; // Array 'a' to store the solution

    // Initialize 'a' with all zeros
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }

    // Try to find a solution for each pair of rows
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Find the common bits between the two rows
            int commonBits = matrix[i][j];

            // Update the corresponding elements in the array 'a'
            a[i] |= commonBits;
            a[j] |= commonBits;
        }
    }

    // Check if the obtained array 'a' satisfies the conditions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] != (a[i] | a[j])) {
                printf("NO\n");
                return;
            }
        }
    }

    // Print the result
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int matrix[100][100];

        // Read the matrix values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        // Find and print the array for each test case
        findArray(n, matrix);
    }

    return 0;
}
