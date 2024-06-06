#include <stdio.h>

int find_min(int arr[], int n);

int main()
{
    int arr[] = {
        14, 54, 65, 45, 98, -4543, 65, -12, -566, 485, 123, 321
    };
    int n = 12;

    int min = find_min(arr, n);

    printf("%d\n", min);

    return 0;
}

int find_min(int arr[], int n)
{
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}