#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) b - * (int *) a;
}

void solve()
{
    int n, i, j, odd = 0, even = 0, f = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        even += arr[i] % 2 == 0;
        odd += arr[i] % 2 == 1;
    }

    if (even % 2 != odd % 2) {
        puts("NO");
    }
    else {
        if (even % 2 == 0) {
            puts("YES");
        }
        else {
            qsort(arr, n, sizeof(int), compare);

            for (i = 0; i < n; i++) {
                for (j = i + 1; j < n; j++) {
                    if (arr[i] - arr[j] == 1) {
                        f = 1;
                        break;
                    }
                }

                if (f == 1) {
                    break;
                }
            }

            puts(f == 1 ? "YES" : "NO");
        }
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