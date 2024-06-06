#include <stdio.h>

// Function to swap 2 arrays
void swapArrays(int a[], int b[], int size)
{
    // Create a temporary array to hold a
    int temp[101];

    // Copy elements from a to temp
    for (int i = 0; i < size; i++) {
        temp[i] = a[i];
    }

    // Copy elements from b to a
    for (int i = 0; i < size; i++) {
        a[i] = b[i];
    }

    // Copy elements from temp to b
    for (int i = 0; i < size; i++) {
        b[i] = temp[i];
    }
}

// Function to merge two sorted arrays into a third array
void mergeArrays(int a[], int b[], int c[], int n1, int n2)
{
    // Declare and initialise variables
    int i = 0, j = 0, k = 0;

    // Merge elements from arrays a and b into array c in sorted order
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            // If the current element in array a is smaller, copy it to array c
            c[k++] = a[i++];
        } else {
            // If the current element in array b is smaller (or equal), copy it to array c
            c[k++] = b[j++];
        }
    }

    // If there are any remaining elements in array a, copy them to array c
    while (i < n1) {
        c[k++] = a[i++];
    }

    // If there are any remaining elements in array b, copy them to array c
    while (j < n2) {
        c[k++] = b[j++];
    }
}

int main()
{
    // Declare variables
    int i, t, size1, size2, size;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Get the size of the 1st array
        scanf("%d", &size1);

        // Declare array of intended size
        int a[size1];

        // Fill the array
        for (i = 0; i < size1; i++) {
            scanf("%d", &a[i]);
        }

        // Get the size of the 2nd array
        scanf("%d", &size2);

        // Declare array of intended size
        int b[size2];

        // Fill the array
        for (i = 0; i < size2; i++) {
            scanf("%d", &b[i]);
        }

        // Size of 3rd array = size1 + size2
        size = size1 + size2;

        // Declare 3rd array
        int c[size];

        // Merge the arrays a and b into c
        mergeArrays(a, b, c, size1, size2);

        // Print the merged array
        printf("%d", c[0]);
        for (i = 1; i < size; i++) {
            printf(" %d", c[i]);
        }
        printf("\n");
    }

    return 0;
}

// Took help from the book and ChatGPT for better understanding