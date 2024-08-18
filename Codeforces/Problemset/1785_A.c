#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i;
    long long spells = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(int), compare);

    spells += arr[0] - 1;
    arr[0] = 1;

    for (i = 1; i < n; i++) {
        spells += 1LL * max(0, arr[i] - min(arr[i], arr[i - 1] + 1));

        arr[i] = min(arr[i], arr[i - 1] + 1);
    }

    printf("%lld\n", spells);
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