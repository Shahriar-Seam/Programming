#include <stdio.h>
#include <limits.h>

void solve()
{
    int n, i, f = 1, min = INT_MAX, min_index = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }

    for (i = min_index + 1; i < n; i++) {
        if ((i > 0) && (arr[i - 1] > arr[i])) {
            f = 0;
            break;
        }
    }

    if (f == 1) {
        printf("%d\n", min_index);
    }
    else {
        puts("-1");
    }
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