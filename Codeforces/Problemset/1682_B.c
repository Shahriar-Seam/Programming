#include <stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i, x = 0;

    scanf("%d", &n);

    int arr[n], indices[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        indices[arr[i]] = i;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] != i) {
            x = max(x, arr[i] & arr[indices[i]]);

            swap(&arr[i], &arr[indices[i]]);
        }
    }

    printf("%d\n", x);
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