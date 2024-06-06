#include <stdio.h>

void solve()
{
    int n, i, j, f = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 2; j < n; j++) {
            if (arr[i] == arr[j]) {
                f = 1;
            }
        }
    }

    puts(f ? "YES" : "NO");
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