#include <stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(arr + j - 1, arr + j);
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}