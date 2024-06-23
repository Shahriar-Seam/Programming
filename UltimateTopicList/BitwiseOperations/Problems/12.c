#include <stdio.h>

void solve()
{
    int n, p, i, mask, length, f = 0;

    scanf("%d %d", &n, &p);

    int arr[p];

    for (i = 0; i < p; i++) {
        scanf("%d", arr + i);
    }

    for (mask = 0; mask <= (1 << p); mask++) {
        length = 0;

        for (i = 0; i < p; i++) {
            if (mask & (1 << i)) {
                length += arr[i];
            }
        }

        if (length == n) {
            f = 1;
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