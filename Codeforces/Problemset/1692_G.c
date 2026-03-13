#include <stdio.h>
#include <stdint.h>

void solve()
{
    int n, k, i, count = 0, len = 1;

    scanf("%d %d", &n, &k);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 1; i < n; i++) {
        if (arr[i - 1] >= 2 * arr[i]) {
            len = 1;
        }
        else {
            len++;
        }

        if (len > k) {
            count++;
        }
    }

    printf("%d\n", count);
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}