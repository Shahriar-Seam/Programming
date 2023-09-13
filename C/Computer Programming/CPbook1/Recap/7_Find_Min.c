#include <stdio.h>

int find_min(int arr[], int n)
{
    int i, min = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int main()
{
    int i, n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = find_min(arr, n);

    printf("Min = %d\n", min);

    return 0;
}