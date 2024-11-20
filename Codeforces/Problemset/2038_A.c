#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, k, i;
    long long sum = 0;

    scanf("%d %d", &n, &k);

    int a[n], b[n], c[n];

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", b + i);
    }

    for (i = 0; i < n; i++) {
        sum += 1LL * a[i] / b[i];
    }

    if (sum < k) {
        for (i = 0; i < n; i++) {
            c[i] = 0;
        }
    }
    else {
        for (i = n - 1; i >= 0; i--) {
            c[i] = min(k, a[i] / b[i]);

            k -= min(k, a[i] / b[i]);
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}