/**
 *    author:  Anonymous_HF
 *    created: 29/05/2024
**/

#include <stdio.h>

int mid(int a, int b, int c)
{
    if ((a >= b && a <= c) || (a >= c && a <= b)) {
        return a;
    }
    if ((b >= a && b <= c) || (b >= c && b <= a)) {
        return b;
    }
    if ((c >= a && c <= b) || (c >= b && c <= a)) {
        return c;
    }
}

void solve()
{
    int n, k, i, f = 0;

    scanf("%d %d", &n, &k);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    if (n == 1) {
        if (arr[0] == k) {
            f = 1;
        }
    }
    else {
        if (arr[0] == k && arr[1] >= k) {
            f = 1;
        }
        if (arr[n - 1] == k && arr[n - 2] >= k) {
            f = 1;
        }

        for (i = 1; i < n - 1; i++) {
            if (arr[i] == k) {
                if ((arr[i - 1] >= k) || (arr[i + 1] >= k)) {
                    f = 1;

                    break;
                }
            }
        }

        if (n > 2) {
            for (i = 2; i < n; i++) {
                if (k == mid(arr[i - 2], arr[i - 1], arr[i])) {
                    f = 1;
                    break;
                }
            }
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