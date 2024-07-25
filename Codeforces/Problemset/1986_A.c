#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

int _min(int count, ...)
{
    int i, min_value = INT_MAX;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        min_value = min(min_value, va_arg(ptr, int));
    }

    va_end(ptr);

    return min_value;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int _max(int count, ...)
{
    int i, max_value = INT_MIN;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        max_value = max(max_value, va_arg(ptr, int));
    }

    va_end(ptr);

    return max_value;
}

void solve()
{
    int a, b, c, fa = 1000, i;

    scanf("%d %d %d", &a, &b, &c);

    for (i = _min(3, a, b, c); i <= _max(3, a, b, c); i++) {
        fa = min(fa, abs(i - a) + abs(i - b) + abs(i - c));
    }

    printf("%d\n", fa);
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