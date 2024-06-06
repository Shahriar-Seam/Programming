#include <stdio.h>

int missing_number(int arr[], int size)
{
    int i, j, present;

    for (i = 1; i <= size; i++) {
        present = 0;
        for (j = 0; j < size - 1; j++) {
            if (arr[j] == i) {
                present = 1;
                break;
            }
        }
        if (present == 0) {
            return i;
            break;
        }
    }

    return j;
}

int main()
{
    // Declare variables
    int i, t, n, missing_num;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Get the size of the array
        scanf("%d", &n);

        // Declare the array
        int arr[n];

        // Fill the array
        for (i = 0; i < n - 1; i++) {
            scanf("%d", &arr[i]);
        }

        // Find the missing number using the function
        missing_num = missing_number(arr, n);

        // Print the missing number
        printf("%d\n", missing_num);
    }

    return 0;
}

// Shows TLE on Both