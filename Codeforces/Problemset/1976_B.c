#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>

int _min(int a, int b)
{
  return a < b ? a : b;
}

int _max(int a, int b)
{
  return a > b ? a : b;
}

void solve()
{
    int n, i, bn, max, min;
    long long count = 1, additional = INT_MAX - 1;

    scanf("%d", &n);

    int a[n], b[n];

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", b + i);
    }

    scanf("%d", &bn);

    for (i = 0; i < n; i++) {
        count += abs(a[i] - b[i]);

        max = _max(a[i], b[i]);
        min = _min(a[i], b[i]);

        if ((bn >= min) && (bn <= max)) {
            additional = 0;
        }
        else {
            additional = _min(additional, _min(abs(max - bn), abs(min - bn)));
        }
    }

    count += additional;

    printf("%lld\n", count);
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


