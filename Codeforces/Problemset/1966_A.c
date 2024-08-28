#include <stdio.h>

void solve()
{
    int n, k, i, f = 0;
    int counter[105] = {};

    scanf("%d %d", &n, &k);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        counter[arr[i]]++;
    }

    for (i = 0; i < 105; i++) {
        if (counter[i] >= k) {
            f = 1;

            break;
        }
    }

    printf("%d\n", (f == 1 ? k - 1 : n));
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