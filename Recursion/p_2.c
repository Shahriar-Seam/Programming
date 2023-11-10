// Write a recursive function to print an array in the
// following order. 
// [0] [n-1] [1] [n-2] ... ... [(n-1)/2] [n/2]

#include <stdio.h>

void recurse(int *arr, int i, int n)
{
    if (i > n / 2) {
        return;
    }

    printf("%d %d\n", arr[i], arr[n - i - 1]);

    recurse(arr, i + 1, n);
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