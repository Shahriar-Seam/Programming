/**
 *    author:  Anonymous_HF
 *    created: 12/05/2024 22:56:46
**/

#include <stdio.h>
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
    int x;
    int y;
    int minimum;
    int maximum;

    scanf("%d", &x);
    scanf("%d", &y);

    minimum = _min(2, x, y);
    maximum = _max(2, x, y);

    printf("%d %d\n", minimum, maximum);
}

int main()
{
    int t;

    fprintf(stderr, "hehe");

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}