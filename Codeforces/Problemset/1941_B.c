#include <stdio.h>

void solve()
{
    int n, i, f = 1;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n - 2; i++) {
        if (arr[i] < 0) {
            break;
        }

        arr[i + 1] -= 2 * arr[i];
        arr[i + 2] -= arr[i];
        arr[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            f = 0;
            break;
        }
    }

    puts(f == 1 ? "YES" : "NO");
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