// You will be given an array of integers
// write a recursive solution to print it in reverse order.

#include <stdio.h>

void recurse(int *arr, int i, int n)
{
    if (i == n) {
        return;
    }

    recurse(arr, i + 1, n);

    printf("%d ", arr[i]);
}

int main()
{
    int n, i, arr[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    recurse(arr, 0, n);

    return 0;
}