#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int n, i, j;

    scanf("%d", &n);

    int arr[n];
    int brr[n - 1];

    for (i = 0; i < n - 1; i++) {
        scanf("%d", brr + i);
    }

    arr[0] = brr[0];

    for (i = 0, j = 1; i < n - 2; i++) {
        arr[j++] = min(brr[i], brr[i + 1]);
    }

    arr[j] = brr[n - 2];

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}