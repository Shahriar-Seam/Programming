#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i;
    long long int diff_sum = 0, max_diff = 0, prev_max = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n; i++) {
        prev_max = max(prev_max, arr[i]);

        diff_sum += 0LL + prev_max - arr[i];

        max_diff = max(max_diff, prev_max - arr[i]);
    }

    printf("%lld\n", max_diff + diff_sum);
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