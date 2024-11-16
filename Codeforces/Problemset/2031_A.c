#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i, count = 0;
    int h[100] = {};

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        h[arr[i]]++;
    }

    for (i = 0; i < 100; i++) {
        count = max(count, h[i]);
    }

    printf("%d\n", n - count);
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