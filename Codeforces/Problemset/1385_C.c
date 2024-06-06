#include <stdio.h>

void solve()
{
    int n, i, count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = n - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1]) {
            break;
        }
    }

    n = ++i;

    for (i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            count = i;
        }
    }

    printf("%d\n", count);
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