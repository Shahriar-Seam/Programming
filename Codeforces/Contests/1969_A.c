#include <stdio.h>

void solve()
{
    int n, i, f = 0;

    scanf("%d", &n);

    int arr[n + 1];

    for (i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 1; i <= n; i++) {
        if (arr[arr[i]] == i) {
            f = 1;
            break;
        }
    }

    puts(f == 1 ? "2" : "3");
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