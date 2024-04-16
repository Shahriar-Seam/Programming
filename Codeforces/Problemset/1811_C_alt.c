#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int n, i, j, f = 0, min_val = INT_MAX;

    scanf("%d", &n);

    int arr[n];
    int brr[n - 1];

    for (i = 0; i < n - 1; i++) {
        scanf("%d", brr + i);

        min_val = min(min_val, brr[i]);
    }
    
    for (i = 0; i < n - 1; i++) {
        printf("%d ", brr[i]);

        if (brr[i] == min_val && f == 0) {
            printf("0 ");

            f = 1;
        }
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