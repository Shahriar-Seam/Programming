#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <limits.h>

#define int long long

int min(int a, int b)
{
    return a < b ? a : b;
}

int _min(int count, ...)
{
    int i, min_value = 4e18;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        min_value = min(min_value, va_arg(ptr, int));
    }

    va_end(ptr);

    return min_value;
}

void solve()
{
    int n, i, sum_a = 0, sum_b = 0, cost = 4e18;

    scanf("%lld", &n);

    int a[n], b[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", a + i);
        
        sum_a += a[i];
    }

    for (i = 0; i < n; i++) {
        scanf("%lld", b + i);
        
        sum_b += b[i];
    }

    for (i = 0; i < n; i++) {
        cost = _min(3, cost, a[i] * n + sum_b, b[i] * n + sum_a);
    }

    printf("%lld\n", cost);
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