#include <stdio.h>

void solve()
{
    int n, i, j;
    int odd[] = {1, 3, 3, 4, 4, 5, 5, 6, 6, 1, 2, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 1, 2};

    scanf("%d", &n);

    if (n <= 25 && (n % 2 == 1)) {
        printf("-1\n");

        return;
    }

    int arr[n];

    if (n % 2 == 1) {
        for (i = 0; i < 27; i++) {
            arr[i] = odd[i];
        }

        for (i, j = 14; i < n; i += 2, j++) {
            arr[i] = j;
            arr[i + 1] = j;
        }
    }
    else {
        for (i = 0, j = 1; i < n - 1; i += 2, j++) {
            arr[i] = j;
            arr[i + 1] = j;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
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