#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

void solve()
{
    int n, i, count = 0, first, second;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(int), compare);

    first = arr[0];
    second = arr[1];

    for (i = 0; i < n; i++) {
        if (arr[i] % first != 0) {
            second = arr[i];

            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] % first == 0) {
            arr[i] = 0;
        }
        else if (arr[i] % second == 0) {
            arr[i] = 0;
        }

        count += (arr[i] != 0);
    }

    puts(count == 0 ? "YES" : "NO");
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