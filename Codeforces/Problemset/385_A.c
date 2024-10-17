#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, c, bleh = 0, i;

    scanf("%d %d", &n, &c);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 1; i < n; i++) {
        bleh = max(bleh, arr[i - 1] - arr[i] - c);
    }

    printf("%d\n", bleh);

    return 0;
}