#include <stdio.h>

void solve()
{
    int n, i, f = 1, count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = n - 2; i >= 0; i--) {
        while (arr[i] > 0 && arr[i] >= arr[i + 1]) {
            arr[i] /= 2;

            count++;
        }
    }

    for (i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) {
            f = 0;

            break;
        }
    }

    printf("%d\n", (f == 1 ? count : -1));
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