#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, t = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    t += arr[0] + 1;

    for (i = 1; i < n; i++) {
        t += abs(arr[i] - arr[i - 1]) + 2;
    }

    printf("%d\n", t);

    return 0;
}