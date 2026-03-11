#include <stdio.h>
#include <stdint.h>

#define int long long

int max(int a, int b)
{
    return a > b ? a : b;
}

int max_sum_subarray(int32_t *arr, int n)
{
    int i, sum = 0, max_sum = -1e18;

    for (i = 0; i < n; i++) {
        sum += arr[i];

        max_sum = max(max_sum, sum);

        sum = max(0, sum);
    }

    return max_sum;
}

void solve()
{
    int32_t n, i;
    long long sum = 0;

    scanf("%d", &n);

    int32_t arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        sum += arr[i];
    }

    if (sum > max(max_sum_subarray(arr, n - 1), max_sum_subarray(arr + 1, n - 1))) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}