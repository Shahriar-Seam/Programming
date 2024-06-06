#include <stdio.h>

int main()
{
    int n, i;
    int arr[1000] = {1, 2, 3, 4};

    scanf("%d", &n);

    for (i = 4; i < n; i++) {
        arr[i] = arr[i - 1] * arr[i - 3] - arr[i - 2] * arr[i - 4];
    }

    printf("%d\n", arr[n - 1]);

    return 0;
}