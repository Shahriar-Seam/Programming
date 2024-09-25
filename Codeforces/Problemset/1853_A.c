#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int n, i, min_diff = 1e9 + 8;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 1; i < n; i++) {
        min_diff = min(min_diff, arr[i] - arr[i - 1]);
    }

    if (min_diff < 0) {
        printf("0\n");
    }
    else {
        printf("%d\n", min_diff / 2 + 1);
    }
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