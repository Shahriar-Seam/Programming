#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int n, k, i;
    long long w_sum = 0, sum = 0;

    scanf("%d %d", &n, &k);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < k; i++) {
        w_sum += arr[i];
    }

    sum = w_sum;

    for (i = k; i < n; i++) {
        w_sum += arr[i] - arr[i - k];

        sum += w_sum;
    }

    printf("%0.10f\n", sum * 1.0 / (n - k + 1));

    return 0;
}