#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 1, 2, 3};
    int result, i, n = 7;

    result = arr[0];

    for (i = 1; i < n; i++) {
        result = result ^ arr[i];
    }

    printf("Result: %d\n", result);

    return 0;
}