#include <stdio.h>

int max_in_array(int arr[], int n);

int main()
{
    int i, n, max;

    printf("Enter number of numbers you want to enter: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = max_in_array(arr, n);

    printf("Max = %d\n", max);

    return 0;
}

int max_in_array(int arr[], int n)
{
    int i, max = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}