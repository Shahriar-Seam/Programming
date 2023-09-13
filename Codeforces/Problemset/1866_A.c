#include <stdio.h>
#include <stdlib.h>

int _min(int arr[], int n)
{
    int m = abs(arr[0]), i;

    for (i = 0; i < n; i++) {
        if (abs(arr[i]) < m) {
            m = abs(arr[i]);
        }
    }

    return m;
}

int main()
{
    int n, i, min;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min = _min(arr, n);

    printf("%d", min);

    return 0;
}