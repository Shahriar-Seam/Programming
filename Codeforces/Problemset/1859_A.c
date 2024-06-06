#include <stdio.h>

int _max(int a, int b)
{
  return a > b ? a : b;
}

void solve()
{
    int n, i, max = 0, max_count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        max = _max(max, arr[i]);
    }

    for (i = 0; i < n; i++) {
        max_count += (arr[i] == max);
    }

    if (max_count == n) {
        printf("%d\n", -1);
    }
    else {
        printf("%d %d\n", n - max_count, max_count);

        for (i = 0; i < n; i++) {
            if (arr[i] != max) {
                printf("%d ", arr[i]);
            }
        }

        printf("\n");

        while (max_count--) {
            printf("%d ", max);
        }
        
        printf("\n");
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